#ifndef PROGRESSBARPROJECT_MYFRAME_H
#define PROGRESSBARPROJECT_MYFRAME_H


#include <wx/wxprec.h>
#include <wx/progdlg.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include "ResourceLoader.h"

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);


private:
    void OnOpen(wxCommandEvent &event);

    void OnExit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);

private:
    wxString selectedFile;


wxDECLARE_EVENT_TABLE();
};


#endif //PROGRESSBARPROJECT_MYFRAME_H
