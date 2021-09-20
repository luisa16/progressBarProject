// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/progdlg.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnOpen(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
wxDECLARE_EVENT_TABLE();
};


enum
{
    ID_Open = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
                EVT_MENU(ID_Open, MyFrame::OnOpen)
                EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    int i, max = 433;

    MyFrame *frame = new MyFrame( "Progress bar", wxPoint(50, 50), wxSize(450, 340) );
    this->SetTopWindow(frame);
    frame->Show( true );

    wxProgressDialog* dialog = new wxProgressDialog(wxT("Wait..."), wxT("Keep waiting..."), max, frame, wxPD_AUTO_HIDE | wxPD_APP_MODAL);

    for(int i = 0; i < max; i++){
        wxMilliSleep(5); //here are computations
        if(i%23) dialog->Update(i);
    }
    dialog->Update(max);
    delete dialog;

    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Open, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnOpen(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
