//
// Created by luisa on 20/09/21.
//

#include "ResourceLoader.h"
#include "Observer.h"
#include <list>
#include <algorithm>
#include <fstream>
#include <string>

void ResourceLoader::registerObserver(Observer *o)  {
    if(o != nullptr) {
        observers.push_back(*o);
    }
}

void ResourceLoader::removeObserver(Observer *o)  {
    if (o!= nullptr){
        std::list<Observer>::iterator it;
        it = find(observers.begin(), observers.end(), *o);
        observers.erase(it);
    }
}

void ResourceLoader::notifyObservers() const {
    for(auto itr=observers.begin(); itr!=observers.end(); ++itr){
        (*itr).update();
    }
}

void ResourceLoader::ReadFile(std::ifstream ReadFile) {
    std::string myText;
    std::ofstream WriteFile("prova_caricata.txt");
    while(getline(ReadFile, myText)){
        WriteFile<<myText;
        WriteFile<<"\n";
    }
    ReadFile.close();
}
