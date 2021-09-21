#ifndef PROGRESSBARPROJECT_PROGRESSBAR_H
#define PROGRESSBARPROJECT_PROGRESSBAR_H


#include "Observer.h"
#include "ResourceLoader.h"

class ProgressBar: public Observer {


public:
    ProgressBar(ResourceLoader *rl);
    void update()override;
    void attach() override;
    void detach() override;

    virtual ~ProgressBar();

private:
    ResourceLoader* rs;

};


#endif //PROGRESSBARPROJECT_PROGRESSBAR_H
