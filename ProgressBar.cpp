#include "ProgressBar.h"
#include <wx/frame.h>
#include "MyFrame.h"
#include <wx/app.h>
#include <wx/progdlg.h>


void ProgressBar::update(){
    updated=true;
    int i;
    int max = rs->getFileSize();
    wxWindow *wxF = wxFrame::FindWindowById(2);
    wxProgressDialog *dialog = new wxProgressDialog(wxT("Wait..."), wxT("Keep waiting..."), max, wxF,wxPD_APP_MODAL | wxPD_AUTO_HIDE);
    for (i = 0; i < max; i+=5) {
        wxMilliSleep(2);
        dialog->Update(i);
    }
    dialog->Update(max);
    delete dialog;
    wxMessageBox("File uploded!",
                 "Upload result", wxOK | wxICON_INFORMATION);
}

void ProgressBar::attach() {
    rs->registerObserver(this);
}

void ProgressBar::detach() {
    rs->removeObserver(this);
}

ProgressBar::ProgressBar(ResourceLoader *rl) {
    this->rs = rl;
    attach();
}

ProgressBar::~ProgressBar() {
    detach();
}

bool ProgressBar::isUpdated() const {
    return updated;
}

