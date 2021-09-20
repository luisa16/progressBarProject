//
// Created by luisa on 20/09/21.
//

#include "ResourceLoader.h"
#include <vector>
#include <algorithm>

void ResourceLoader::registerObserver(Observer *o)  {
    if(o != nullptr) {
        observers.push_back(*o);
    }
}

void ResourceLoader::removeObserver(Observer *o)  {
    if (o!= nullptr){
        std::vector<Observer>::iterator it;
        it = find(observers.begin(), observers.end(), *o);
        observers.erase(it);
    }
}

void ResourceLoader::notifyObservers() const {
    for(auto itr=observers.begin(); itr!=observers.end(); ++itr){
        (*itr).update();
    }
}
