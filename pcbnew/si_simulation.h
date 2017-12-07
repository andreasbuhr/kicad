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

class BOARD;
class DIALOG_SI_CONTROL;

// a class holding everything related to SI simulation
class SI_SIMULATION
{
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

private:
    BOARD *m_board;
    double m_maxFreq;
    double m_domainSize;
    double m_linesPerWavelength;
};

#endif // SI_SIMULATION_H
