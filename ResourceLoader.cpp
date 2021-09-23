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
    }
}

std::fstream ResourceLoader::ReadFile(const wxString &p){
    fileName = basename(p);
    std::string path = std::string(p);
    std::ifstream ReadFile(path, std::ios::binary | std::ios::ate);
    setFileSize(static_cast<int>(ReadFile.tellg()));
    notifyObservers();
    notified= true;
    std::fstream readFile(path);
    std::string myText;
    std::fstream WriteFile(fileName, std::fstream::out);
    while (getline(readFile, myText)) {
        WriteFile << myText;
        WriteFile << "\n";
    }
    readFile.close();
    return WriteFile;
}

int ResourceLoader::getFileSize() const {
    return fileSize;
}

void ResourceLoader::setFileSize(int s) {
    this->fileSize = s;
}

const std::string &ResourceLoader::getFileName()const {
    return fileName;
}

bool ResourceLoader::isNotified() const {
    return notified;
}
