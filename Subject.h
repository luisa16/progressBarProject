#ifndef PROGRESSBARPROJECT_SUBJECT_H
#define PROGRESSBARPROJECT_SUBJECT_H
#include "Observer.h"

class Subject {

public:
    virtual void registerObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
    virtual void notifyObservers()=0;

    virtual ~Subject(){};
};

#endif //PROGRESSBARPROJECT_SUBJECT_H
