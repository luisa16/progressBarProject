//
// Created by luisa on 20/09/21.
//

#ifndef PROGRESSBARPROJECT_SUBJECT_H
#define PROGRESSBARPROJECT_SUBJECT_H
#include "Observer.h"

class Subject {
protected:
    virtual ~Subject(){};

public:
    virtual void registerObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
    virtual void notifyObservers() const=0;
};


#endif //PROGRESSBARPROJECT_SUBJECT_H
