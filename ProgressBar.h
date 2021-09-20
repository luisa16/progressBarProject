//
// Created by luisa on 20/09/21.
//

#ifndef PROGRESSBARPROJECT_PROGRESSBAR_H
#define PROGRESSBARPROJECT_PROGRESSBAR_H


#include "Observer.h"

class ProgressBar: Observer {

private:
    int id;
public:
    int getId() const;
    void update();
};


#endif //PROGRESSBARPROJECT_PROGRESSBAR_H
