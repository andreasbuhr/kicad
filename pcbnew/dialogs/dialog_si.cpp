/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2017 Andreas Buhr <andreas@andreasbuhr.de>
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

#include "dialog_si.h"

#include <wxPcbStruct.h>
#include <common.h>


#include <class_board.h>

#include <boost/lexical_cast.hpp>
#include <sstream>
#include <iomanip>
#include <cstdlib>

void PCB_EDIT_FRAME::ShowSIDialog( )
{
    // Switch the locale to standard C (needed to print floating point numbers)
    LOCALE_IO toggle;

    auto si_simulation = GetBoard()->m_siSimulation;

    DIALOG_SI_CONTROL dlg( this, GetBoard() );

    {
        std::ostringstream ss;
        ss << std::setprecision(5);
        ss << si_simulation->getMaxFreq();
        dlg.m_MaxFrequencyCtrl->SetValue(ss.str());
    }
    {
        std::ostringstream ss;
        ss << std::setprecision(5);
        ss << si_simulation->getDomainSize();
        dlg.m_DomainSizeCtrl->SetValue(ss.str());
    }
    {
        std::ostringstream ss;
        ss << std::setprecision(5);
        ss << si_simulation->getLinesPerWavelength();
        dlg.m_LinesPerWavelengthCtrl->SetValue(ss.str());
    }
    {
        std::ostringstream ss;
        ss << std::setprecision(5);
        ss << si_simulation->getMin_number_of_domains();
        dlg.m_NumberOfDomainsCtrl->SetValue(ss.str());
    }

    if( dlg.ShowModal() == wxID_CANCEL)
        return;

    // use all the settings
    try{
        si_simulation->setMaxFreq(boost::lexical_cast<double>(dlg.m_MaxFrequencyCtrl->GetValue().ToStdString()));
        si_simulation->setDomainSize(boost::lexical_cast<double>(dlg.m_DomainSizeCtrl->GetValue().ToStdString()));
        si_simulation->setLinesPerWavelength(boost::lexical_cast<double>(dlg.m_LinesPerWavelengthCtrl->GetValue().ToStdString()));
        si_simulation->setMin_number_of_domains(boost::lexical_cast<int>(dlg.m_NumberOfDomainsCtrl->GetValue().ToStdString()));
        si_simulation->BuildMesh();
    }
    catch(boost::bad_lexical_cast &){
        std::abort();
    }
}


DIALOG_SI_CONTROL::DIALOG_SI_CONTROL(wxWindow* parent , BOARD *aBoard)
:
DIALOG_SI_CONTROL_BASE( parent ), m_board(aBoard)
{

}

void DIALOG_SI_CONTROL::OnActivateDlg( wxActivateEvent& event )
{
// TODO: Implement OnActivateDlg
}

void DIALOG_SI_CONTROL::OnCancelClick( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

void DIALOG_SI_CONTROL::OnOkClick( wxCommandEvent& event )
{
    EndModal(wxID_OK);
}

