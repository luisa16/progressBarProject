#include "ProgressBar.h"
#include <wx/frame.h>
#include "MyFrame.h"
#include <wx/app.h>
#include <wx/progdlg.h>



void ProgressBar::update() {
    if(rs->getSelected()) {
        int i;
        int max = rs->getFileSize();
        //MyFrame *frame = new MyFrame("Progress bar", wxPoint(50, 50), wxSize(450, 340));
        wxWindow* wxF= wxFrame::FindWindowById(2);
        //frame->Show(true);

        wxProgressDialog *dialog = new wxProgressDialog(wxT("Wait..."), wxT("Keep waiting..."), max, wxF, wxPD_APP_MODAL| wxPD_AUTO_HIDE);

        for(i=0; i<max; i++){
            wxMilliSleep(2);
            dialog->Update(i);
        }
        /*while(rs->getSelected()){
            if(i<max){
                wxMilliSleep(1); //here are computations
                dialog->Update(i);
                i++;
            } *//*else
                wxMessageBox( "It takes too much time, retry later!",
                              "Warning:time over limit", wxOK | wxICON_WARNING );*//*
        }*/
        dialog->Update(max);
        delete dialog;
        wxMessageBox( "Successful uploading !",
                      "Uploading result", wxOK | wxICON_HAND );
    }
}

void ProgressBar::attach() {
    rs->registerObserver(this);
}

void ProgressBar::detach() {
    rs->removeObserver(this);
}

ProgressBar::ProgressBar(ResourceLoader *rl){
    this->rs=rl;
    attach();
}

ProgressBar::~ProgressBar(){
    detach();
}

