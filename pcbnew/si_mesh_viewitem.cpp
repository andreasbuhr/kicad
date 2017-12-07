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

/**
 * @file si_mesh_viewitem.cpp
 * @brief Class that draws the triangle mesh used for SI simulation.
 */

#include <si_mesh_viewitem.h>
#include <gal/graphics_abstraction_layer.h>
#include <layers_id_colors_and_visibility.h>
#include <pcb_painter.h>
#include <si_simulation.h>

#include <memory>

#include <view/view.h>

namespace KIGFX {

SI_MESH_VIEWITEM::SI_MESH_VIEWITEM(std::shared_ptr<SI_SIMULATION> asiSimulation ) :
        EDA_ITEM( NOT_USED ),
        m_siSimulation(asiSimulation)
{
}


const BOX2I SI_MESH_VIEWITEM::ViewBBox() const
{
    return m_siSimulation->m_bbox;
}

void SI_MESH_VIEWITEM::ViewDraw( int aLayer, KIGFX::VIEW* aView ) const
{

    auto gal = aView->GetGAL();
    gal->SetIsStroke( true );
    gal->SetStrokeColor(COLOR4D(WHITE));
    gal->SetIsFill( false );
    gal->SetLineWidth( 500000.0 );
    auto& sim(m_siSimulation);

    // draw bounding box
    gal->DrawRectangle(sim->m_bbox.GetOrigin(), sim->m_bbox.GetEnd());

    // draw DD
    if(sim->m_domain_boundaries_x.size() >= 2 && sim->m_domain_boundaries_y.size() >= 2){
        gal->SetStrokeColor(COLOR4D(LIGHTBLUE));
        gal->SetLineWidth( 200000.0 );

        double x_min = sim->m_domain_boundaries_x.front();
        double x_max = sim->m_domain_boundaries_x.back();
        double y_min = sim->m_domain_boundaries_y.front();
        double y_max = sim->m_domain_boundaries_y.back();

        for(double x_val : sim->m_domain_boundaries_x){
            gal->DrawLine(VECTOR2D(x_val, y_min), VECTOR2D(x_val, y_max));
        }
        for(double y_val : sim->m_domain_boundaries_y){
            gal->DrawLine(VECTOR2D(x_min, y_val), VECTOR2D(x_max, y_val));
        }
    }

    gal->SetStrokeColor(COLOR4D(LIGHTGREEN));
    gal->SetLineWidth( 10000.0 );
    for(auto& map : sim->m_polygons)
        for(auto& poly : map)
            gal->DrawPolygon(poly.second);
}


void SI_MESH_VIEWITEM::ViewGetLayers( int aLayers[], int& aCount ) const
{
    aCount = 1;
    aLayers[0] = LAYER_SI_MESH;
}

}
