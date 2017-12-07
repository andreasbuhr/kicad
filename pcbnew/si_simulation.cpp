/*
 * This program source code file is part of KICAD, a free EDA CAD application.
 *
 * Copyright (C) 2017 Andreas Buhr
 * @author Andreas Buhr <andreas@andreasbuhr.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "si_simulation.h"

#include <class_board.h>
#include <class_zone.h>
#include <class_pad.h>
#include <class_track.h>
#include <class_drawsegment.h>
#include <class_module.h>
#include <wxPcbStruct.h>
#include <tool/tool_manager.h>
#include <tool/tool_action.h>
#include <tools/pcb_actions.h>



SI_SIMULATION::SI_SIMULATION(BOARD *aBoard)
    : m_board(aBoard),
      m_min_number_of_domains(100),
      m_maxFreq(1.),
      m_domainSize(0.2),
      m_linesPerWavelength(20)
{

}

SI_SIMULATION::~SI_SIMULATION()
{

}

void SI_SIMULATION::BuildMesh()
{
    // step 1: find bounding box
    m_bbox = m_board->GetBoardEdgesBoundingBox();

    // step 2: calculate domain decomposition:
    // speed of light in nm/s
    double c = 299792458. * 1e9;
    // speed of light is slower in PCBs:
    c /= sqrt( 4.5 );

    // maxFreq is stored in GHz
    double lambda = c / ( m_maxFreq * 1e9 );
    double domain_maxsize_freq = lambda * m_domainSize;

    // maximum domain size to reach desired number of domains:
    double area_per_domain = m_bbox.GetArea() / m_min_number_of_domains;
    double domain_maxsize_num = sqrt( area_per_domain );

    double domain_maxsize = std::min( domain_maxsize_freq, domain_maxsize_num );

    int num_domains_x = ceil( m_bbox.GetWidth() / domain_maxsize );
    int num_domains_y = ceil( m_bbox.GetHeight() / domain_maxsize );

    m_numDomains = num_domains_x * num_domains_y;

    double domain_size_x = double( m_bbox.GetWidth() ) / num_domains_x;
    double domain_size_y = double( m_bbox.GetHeight() ) / num_domains_y;

    m_domain_boundaries_x.clear();
    for( int i = 0; i < num_domains_x; ++i )
    {
        m_domain_boundaries_x.push_back( m_bbox.GetLeft() + i * domain_size_x );
    }
    m_domain_boundaries_x.push_back( m_bbox.GetRight() );

    m_domain_boundaries_y.clear();
    for( int i = 0; i < num_domains_y; ++i )
    {
        m_domain_boundaries_y.push_back( m_bbox.GetTop() + i * domain_size_y );
    }
    m_domain_boundaries_y.push_back( m_bbox.GetBottom() );

    m_domain_boxes.clear();
    m_domain_polys.clear();
    m_polygons.clear();
    m_polygons.resize(m_numDomains);

    // create bounding box and polygon for each domain:
    for( int domain = 0; domain < m_numDomains; ++domain )
    {
        int      domain_y = domain / num_domains_x;
        int      domain_x = domain % num_domains_x;
        EDA_RECT domain_bbox(
                wxPoint( m_domain_boundaries_x[domain_x], m_domain_boundaries_y[domain_y] ),
                wxSize( domain_size_x, domain_size_y ) );
        m_domain_boxes.push_back( domain_bbox );
        SHAPE_POLY_SET   domain_poly;
        SHAPE_LINE_CHAIN chain( VECTOR2I( domain_bbox.GetLeft(), domain_bbox.GetTop() ),
                VECTOR2I( domain_bbox.GetLeft(), domain_bbox.GetBottom() ),
                VECTOR2I( domain_bbox.GetRight(), domain_bbox.GetBottom() ),
                VECTOR2I( domain_bbox.GetRight(), domain_bbox.GetTop() ) );
        chain.SetClosed( true );
        domain_poly.AddOutline( chain );
        m_domain_polys.push_back( domain_poly );
    }

    for( TRACK* track : m_board->Tracks() )
    {
        addItemToPolygons( track );
    }
    for( auto mod : m_board->Modules() )
    {
        for( auto pad : mod->Pads() )
            addItemToPolygons( pad );
    }
    for( auto zone : m_board->Zones() ){
        addItemToPolygons( zone );
    }
}

void SI_SIMULATION::setMaxFreq(double f)
{
    m_maxFreq = f;
}

double SI_SIMULATION::getMaxFreq()
{
    return m_maxFreq;
}

double SI_SIMULATION::getDomainSize() const
{
    return m_domainSize;
}

void SI_SIMULATION::setDomainSize(double domainSize)
{
    m_domainSize = domainSize;
}

double SI_SIMULATION::getLinesPerWavelength() const
{
    return m_linesPerWavelength;
}

void SI_SIMULATION::setLinesPerWavelength(double linesPerWavelength)
{
    m_linesPerWavelength = linesPerWavelength;
}

int SI_SIMULATION::getMin_number_of_domains() const
{
    return m_min_number_of_domains;
}

void SI_SIMULATION::setMin_number_of_domains(int min_number_of_domains)
{
    m_min_number_of_domains = min_number_of_domains;
}

void SI_SIMULATION::addItemToPolygons(const BOARD_CONNECTED_ITEM *item)
{
    // todo: why do we need this?
    if(! (item->GetNetCode() < m_board->GetNetCount()))
        return;

    auto bbox = item->GetBoundingBox();
    SHAPE_POLY_SET pset;
    const int segsPerCircle = 16;
    double correctionFactor = 1.0 / cos( M_PI / (double) segsPerCircle );
    item->TransformShapeWithClearanceToPolygon( pset, 0, segsPerCircle, correctionFactor );

    for( int domain = 0; domain < m_numDomains; ++domain ){
        if(!bbox.Intersects(m_domain_boxes[domain]))
            continue;
        SHAPE_POLY_SET psetcopy(pset);
        psetcopy.BooleanIntersection(m_domain_polys[domain], SHAPE_POLY_SET::PM_FAST);
        if(!(psetcopy.BBox().GetArea()>0))
            continue;
        m_polygons[domain][item->GetLayer()].BooleanAdd(psetcopy, SHAPE_POLY_SET::PM_FAST);
    }
}
