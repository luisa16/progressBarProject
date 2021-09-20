//
// Created by luisa on 20/09/21.
//

#ifndef PROGRESSBARPROJECT_RESOURCELOADER_H
#define PROGRESSBARPROJECT_RESOURCELOADER_H
#include "Subject.h"
#include "Observer.h"
#include <vector>
#include <algorithm>


class ResourceLoader:Subject {

public:

    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o)override;

    void notifyObservers() const override;



private:
    std::vector<Observer> observers;
};


#endif //PROGRESSBARPROJECT_RESOURCELOADER_H
