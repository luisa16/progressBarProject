#include <wx/wxprec.h>
#include <wx/progdlg.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include "ProgressBar.h"
#include "MyFrame.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};


wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    auto *frame = new MyFrame( "File Loader", wxPoint(50, 50), wxSize(450, 340));
    this->SetTopWindow(frame);
    frame->Show( true );

    return true;
}



