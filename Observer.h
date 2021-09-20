//
// Created by luisa on 20/09/21.
//

#ifndef PROGRESSBARPROJECT_OBSERVER_H
#define PROGRESSBARPROJECT_OBSERVER_H


class Observer {
protected:
    virtual ~Observer(){};
public:
    virtual void update() const =0;

};


#endif //PROGRESSBARPROJECT_OBSERVER_H
