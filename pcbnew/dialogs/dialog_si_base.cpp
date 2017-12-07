///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dialog_si_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_SI_CONTROL_BASE::DIALOG_SI_CONTROL_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* m_MainSizer;
	m_MainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* m_CommandSizer;
	m_CommandSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerOptions;
	bSizerOptions = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextOptions = new wxStaticText( this, wxID_ANY, _("Options:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextOptions->Wrap( -1 );
	m_staticTextOptions->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	
	bSizerOptions->Add( m_staticTextOptions, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizerOptsSettings;
	bSizerOptsSettings = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerOptsSettings->Add( 20, 20, 0, 0, 5 );
	
	wxBoxSizer* bSizerOptSettings;
	bSizerOptSettings = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgMinValuesSizer;
	fgMinValuesSizer = new wxFlexGridSizer( 4, 3, 0, 0 );
	fgMinValuesSizer->AddGrowableCol( 1 );
	fgMinValuesSizer->SetFlexibleDirection( wxHORIZONTAL );
	fgMinValuesSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_maxFrequency = new wxStaticText( this, wxID_ANY, _("Maximum frequency"), wxDefaultPosition, wxDefaultSize, 0 );
	m_maxFrequency->Wrap( -1 );
	m_maxFrequency->SetToolTip( _("Enter the minimum acceptable value for a track width") );
	
	fgMinValuesSizer->Add( m_maxFrequency, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_MaxFrequencyCtrl = new wxTextCtrl( this, wxID_ANY, _("1.5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgMinValuesSizer->Add( m_MaxFrequencyCtrl, 0, wxEXPAND|wxALL, 5 );
	
	m_MaximumFrequencyUnit = new wxStaticText( this, wxID_ANY, _("GHz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MaximumFrequencyUnit->Wrap( -1 );
	m_MaximumFrequencyUnit->SetToolTip( _("Enter the minimum acceptable value for a track width") );
	
	fgMinValuesSizer->Add( m_MaximumFrequencyUnit, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_ViaMinTitle = new wxStaticText( this, wxID_ANY, _("Domain Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ViaMinTitle->Wrap( -1 );
	m_ViaMinTitle->SetHelpText( _("Enter the minimum acceptable diameter for a standard via") );
	
	fgMinValuesSizer->Add( m_ViaMinTitle, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_DomainSizeCtrl = new wxTextCtrl( this, wxID_ANY, _("0.3"), wxDefaultPosition, wxDefaultSize, 0 );
	fgMinValuesSizer->Add( m_DomainSizeCtrl, 0, wxALL|wxEXPAND, 5 );
	
	m_ViaMinUnit = new wxStaticText( this, wxID_ANY, _("wavelength"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ViaMinUnit->Wrap( -1 );
	m_ViaMinUnit->SetHelpText( _("Enter the minimum acceptable diameter for a standard via") );
	
	fgMinValuesSizer->Add( m_ViaMinUnit, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	m_MicroViaMinTitle = new wxStaticText( this, wxID_ANY, _("Meshlines per Wavelength"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MicroViaMinTitle->Wrap( -1 );
	m_MicroViaMinTitle->SetToolTip( _("Enter the minimum acceptable diameter for a micro via") );
	
	fgMinValuesSizer->Add( m_MicroViaMinTitle, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_LinesPerWavelengthCtrl = new wxTextCtrl( this, wxID_ANY, _("20"), wxDefaultPosition, wxDefaultSize, 0 );
	fgMinValuesSizer->Add( m_LinesPerWavelengthCtrl, 0, wxALL|wxEXPAND, 5 );
	
	m_MicroViaMinUnit = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MicroViaMinUnit->Wrap( -1 );
	m_MicroViaMinUnit->SetToolTip( _("Enter the minimum acceptable diameter for a micro via") );
	
	fgMinValuesSizer->Add( m_MicroViaMinUnit, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );
	
	
	bSizerOptSettings->Add( fgMinValuesSizer, 0, wxEXPAND, 5 );
	
	
	bSizerOptsSettings->Add( bSizerOptSettings, 1, wxEXPAND, 5 );
	
	
	bSizerOptions->Add( bSizerOptsSettings, 1, wxEXPAND, 5 );
	
	
	bSizerOptions->Add( 10, 5, 0, 0, 5 );
	
	
	m_CommandSizer->Add( bSizerOptions, 1, wxEXPAND, 5 );
	
	
	m_MainSizer->Add( m_CommandSizer, 0, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	m_MainSizer->Add( m_sdbSizer1, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( m_MainSizer );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( DIALOG_SI_CONTROL_BASE::OnActivateDlg ) );
	m_sdbSizer1Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_SI_CONTROL_BASE::OnCancelClick ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_SI_CONTROL_BASE::OnOkClick ), NULL, this );
}

DIALOG_SI_CONTROL_BASE::~DIALOG_SI_CONTROL_BASE()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( DIALOG_SI_CONTROL_BASE::OnActivateDlg ) );
	m_sdbSizer1Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_SI_CONTROL_BASE::OnCancelClick ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_SI_CONTROL_BASE::OnOkClick ), NULL, this );
	
}
