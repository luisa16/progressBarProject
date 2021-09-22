#ifndef PROGRESSBARPROJECT_PROGRESSBAR_H
#define PROGRESSBARPROJECT_PROGRESSBAR_H


#include "Observer.h"
#include "ResourceLoader.h"

class ProgressBar : public Observer {


public:
    ProgressBar(ResourceLoader *rl);

    void update() override;

    void attach() override;

    void detach() override;

    bool isNotifyReceived() const;

    virtual ~ProgressBar();

private:
    ResourceLoader *rs;
    bool notifyReceived=false;


};


#endif //PROGRESSBARPROJECT_PROGRESSBAR_H
