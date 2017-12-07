///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOG_SI_BASE_H__
#define __DIALOG_SI_BASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_SI_CONTROL_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_SI_CONTROL_BASE : public DIALOG_SHIM
{
	private:
	
	protected:
		wxStaticText* m_staticTextOptions;
		wxStaticText* m_maxFrequency;
		wxStaticText* m_MaximumFrequencyUnit;
		wxStaticText* m_ViaMinTitle;
		wxStaticText* m_ViaMinUnit;
		wxStaticText* m_MicroViaMinTitle;
		wxStaticText* m_MicroViaMinUnit;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnActivateDlg( wxActivateEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxTextCtrl* m_MaxFrequencyCtrl;
		wxTextCtrl* m_DomainSizeCtrl;
		wxTextCtrl* m_LinesPerWavelengthCtrl;
		
		DIALOG_SI_CONTROL_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("SI Control"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 679,211 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~DIALOG_SI_CONTROL_BASE();
	
};

#endif //__DIALOG_SI_BASE_H__
