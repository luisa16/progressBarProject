#include "ResourceLoader.h"
#include "Observer.h"
#include <fstream>
#include <string>

void ResourceLoader::registerObserver(Observer *o)  {
    if(o != nullptr) {
        observers.push_back(o);
    }
}

void ResourceLoader::removeObserver(Observer *o)  {
    if (o!= nullptr){
        observers.remove(o);
    }
}

void ResourceLoader::notifyObservers() {
    for(auto & observer : observers){
        observer->update();
    }
}

void ResourceLoader::ReadFile(const wxString& p) {
    selected=true;
    hasSelected();
    std::string path=std::string(p);
    std::ifstream ReadFile(path, std::ios::binary | std::ios::ate);
    fileSize=ReadFile.tellg();
    std::ifstream readFile(path);
    wxMessageBox(std::to_string(fileSize),
                  "About progress bar project", wxOK | wxICON_INFORMATION );
    std::string myText;
    std::ofstream WriteFile("prova2.txt");
    while(getline(readFile, myText)){
        WriteFile<<myText;
        WriteFile<<"\n";
    }
    selected=false;
    readFile.close();
}

void ResourceLoader::hasSelected() {
    if(selected){
        notifyObservers();

    }
}

bool ResourceLoader::getSelected() const {
    return selected;
}

int ResourceLoader::getFileSize() const {
    return fileSize;
}
