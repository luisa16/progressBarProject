#ifndef PROGRESSBARPROJECT_RESOURCELOADER_H
#define PROGRESSBARPROJECT_RESOURCELOADER_H
#include "Subject.h"
#include "Observer.h"
#include <list>
#include <algorithm>
#include<fstream>
#include "MyFrame.h"


class ResourceLoader: public Subject {

public:
    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notifyObservers() override;

    void ReadFile(const wxString& p);
    void hasSelected();
    bool getSelected() const;




private:
    std::list<Observer*> observers;
    bool selected=false;
    int fileSize;
public:
    void setFileSize(int s);
    int getFileSize() const;

};


#endif //PROGRESSBARPROJECT_RESOURCELOADER_H
