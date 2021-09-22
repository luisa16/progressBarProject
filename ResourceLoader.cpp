#include "ResourceLoader.h"
#include "Observer.h"
#include <fstream>
#include <string>
#include <wx/wfstream.h>

void ResourceLoader::registerObserver(Observer *o) {
    if (o != nullptr) {
        observers.push_back(o);
    }
}

void ResourceLoader::removeObserver(Observer *o) {
    if (o != nullptr) {
        observers.remove(o);
    }
}

void ResourceLoader::notifyObservers() {
    for (auto &observer: observers) {
        observer->update();
        notified=true;
    }
}

std::fstream ResourceLoader::ReadFile(const wxString &p) {
    /*wxString fileName=wxFileNameFromPath(p);
    auto* wxFile=new wxFileStream(p);*/
    fileName = basename(p);
    std::string path = std::string(p);
    std::ifstream ReadFile(path, std::ios::binary | std::ios::ate);
    setFileSize(static_cast<int>(ReadFile.tellg()));
    selected = true;
    hasSelected();
    std::fstream readFile(path);
    std::string myText;
    std::fstream WriteFile("prova2.txt", std::fstream::out);
    while (getline(readFile, myText)) {
        WriteFile << myText;
        WriteFile << "\n";
    }
    selected = false;
    readFile.close();
    return WriteFile;
}

void ResourceLoader::hasSelected() {
    if (selected) {
        notifyObservers();

    }
}

bool ResourceLoader::getSelected() const {
    return selected;
}

int ResourceLoader::getFileSize() const {
    return fileSize;
}

void ResourceLoader::setFileSize(int s) {
    this->fileSize = s;
}

std::string &ResourceLoader::getFileName() {
    return fileName;
}

const std::list<Observer *> &ResourceLoader::getObservers() const {
    return observers;
}

bool ResourceLoader::isNotified() const {
    return notified;
}
