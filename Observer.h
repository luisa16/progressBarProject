#ifndef PROGRESSBARPROJECT_OBSERVER_H
#define PROGRESSBARPROJECT_OBSERVER_H

class Observer {

public:
    virtual ~Observer() {};

    virtual void update() = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;

};


#endif //PROGRESSBARPROJECT_OBSERVER_H
