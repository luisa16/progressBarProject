#include "ProgressBar.h"
#include <wx/frame.h>
#include "MyFrame.h"
#include <wx/app.h>
#include <wx/progdlg.h>


void ProgressBar::update() {
    updated=true;
    if (rs->getSelected()) {
        int i;
        int max = rs->getFileSize();
        //MyFrame *frame = new MyFrame("Progress bar", wxPoint(50, 50), wxSize(450, 340));
        wxWindow *wxF = wxFrame::FindWindowById(2);
        //frame->Show(true);

        wxProgressDialog *dialog = new wxProgressDialog(wxT("Wait..."), wxT("Keep waiting..."), max, wxF,wxPD_APP_MODAL | wxPD_AUTO_HIDE);

        for (i = 0; i < max; i+=5) {
            wxMilliSleep(2);
            dialog->Update(i);
        }

        dialog->Update(max);
        delete dialog;
        wxMessageBox(rs->getFileName().append(" uploded!"),
                     "Upload result", wxOK | wxICON_INFORMATION);

    }
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

