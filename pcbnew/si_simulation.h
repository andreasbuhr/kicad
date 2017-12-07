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

#ifndef SI_SIMULATION_H
#define SI_SIMULATION_H

#include <dialogs/dialog_si.h>
#include <si_mesh_viewitem.h>
#include <class_eda_rect.h>

#include <geometry/shape_poly_set.h>

class BOARD;
class DIALOG_SI_CONTROL;
class BOARD_CONNECTED_ITEM;

// a class holding everything related to SI simulation
class SI_SIMULATION
{
    friend class KIGFX::SI_MESH_VIEWITEM;
public:
    SI_SIMULATION( BOARD* aBoard );
    ~SI_SIMULATION();


    /**
     * Function BuildMesh()
     * Builds the prism mesh for SI simulation.
     */
    void BuildMesh();
    void setMaxFreq(double f);
    double getMaxFreq();

    double getDomainSize() const;
    void setDomainSize(double domainSize);

    double getLinesPerWavelength() const;
    void setLinesPerWavelength(double linesPerWavelength);

    int getMin_number_of_domains() const;
    void setMin_number_of_domains(int min_number_of_domains);

private:
    BOARD *m_board;
    int m_min_number_of_domains;
    double m_maxFreq;
    double m_domainSize;
    double m_linesPerWavelength;

    EDA_RECT m_bbox;
    std::vector<double> m_domain_boundaries_x;
    std::vector<double> m_domain_boundaries_y;

    void addItemToPolygons(const BOARD_CONNECTED_ITEM* item);

    int m_numDomains;
    // for intersection checks:
    std::vector<EDA_RECT> m_domain_boxes;
    // for boolean intersection
    std::vector<SHAPE_POLY_SET> m_domain_polys;
    // the resulting polygons on each layer
    std::vector<std::map<PCB_LAYER_ID,SHAPE_POLY_SET>> m_polygons;
};

#endif // SI_SIMULATION_H
