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
    ResourceLoader(int fs = 0, std::string fn = "", bool n=false) : fileSize(fs), fileName(fn), notified(n) {};

    void registerObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() override;

    std::fstream ReadFile(const wxString &p);

    const std::string &getFileName()const;
    bool isNotified() const;
    void setFileSize(int s);
    int getFileSize() const;


private:
    std::list<Observer *> observers;
    std::string fileName;
    int fileSize;
    bool notified;
};


#endif //PROGRESSBARPROJECT_RESOURCELOADER_H
