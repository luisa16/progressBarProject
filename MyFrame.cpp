#include "MyFrame.h"
#include <wx/wxprec.h>
#include <wx/progdlg.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include "ResourceLoader.h"
#include "ProgressBar.h"

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    auto *frame = new MyFrame("File Loader", wxPoint(50, 50), wxSize(450, 340));
    this->SetTopWindow(frame);
    frame->Show(true);

    return true;
}

enum {
    ID_Open = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
                EVT_MENU(ID_Open, MyFrame::OnOpen)
                EVT_MENU(wxID_EXIT, MyFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(NULL, 2, title, pos, size) {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Open, "&Open...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to file loader!");


}

void MyFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a File loader with progress bar while loading",
                 "About progress bar project", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnOpen(wxCommandEvent &event) {
    wxFileDialog *fileDialog = new wxFileDialog(this);
    if (fileDialog->ShowModal() == wxID_OK) {
        selectedFile = fileDialog->GetPath();
        auto rs = new ResourceLoader();
        auto pr = new ProgressBar(rs);
        rs->ReadFile(static_cast<const wxString &> (selectedFile));

    }
    fileDialog->Destroy();
}

