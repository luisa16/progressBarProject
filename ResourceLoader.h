#ifndef PROGRESSBARPROJECT_RESOURCELOADER_H
#define PROGRESSBARPROJECT_RESOURCELOADER_H

#include "Subject.h"
#include "Observer.h"
#include <list>
#include <algorithm>
#include<fstream>
#include "MyFrame.h"


class ResourceLoader : public Subject {

public:
    ResourceLoader(bool s = false, int fs = 0, std::string fn = "") : selected(s), fileSize(fs), fileName(fn) {};

    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notifyObservers() override;

    std::fstream ReadFile(const wxString &p);


    void hasSelected();

    bool getSelected() const;

    std::string &getFileName();

    void setFileSize(int s);

    int getFileSize() const;


private:
    std::list<Observer *> observers;
public:
    const std::list<Observer *> &getObservers() const;

private:
    bool selected;
    int fileSize;
    std::string fileName;
    bool notified=false;
public:
    bool isNotified() const;


};


#endif //PROGRESSBARPROJECT_RESOURCELOADER_H
