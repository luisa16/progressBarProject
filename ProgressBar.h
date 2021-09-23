#ifndef PROGRESSBARPROJECT_PROGRESSBAR_H
#define PROGRESSBARPROJECT_PROGRESSBAR_H


#include "Observer.h"
#include "ResourceLoader.h"

class ProgressBar : public Observer {

public:
    ProgressBar(ResourceLoader *rl);
    virtual ~ProgressBar();

    void update() override;
    void attach() override;
    void detach() override;

    bool isUpdated() const;

private:
    ResourceLoader *rs;
    bool updated=false;


};


#endif //PROGRESSBARPROJECT_PROGRESSBAR_H
