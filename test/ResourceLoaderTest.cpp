#include "gtest/gtest.h"
#include "../ResourceLoader.h"
#include "../ProgressBar.h"


TEST(ResourceLoader, TestConstructor) {

    ResourceLoader rs;

    ASSERT_EQ(0, rs.getFileSize());
    ASSERT_FALSE(rs.getSelected());
    ASSERT_EQ("", rs.getFileName());
    ASSERT_FALSE(rs.isNotified());
}

TEST(ResourceLoader, TestRegisterUnregister) {
    ResourceLoader rs;
    Observer *pr = new ProgressBar(&rs);
    //rs.registerObserver(pr);
    auto i = std::find(rs.getObservers().begin(), rs.getObservers().end(), pr);
    ASSERT_EQ(i, rs.getObservers().begin());
    rs.removeObserver(pr);
    ASSERT_TRUE(rs.getObservers().empty());
}


TEST(ResourceLoader, TestReadFile) {
    ResourceLoader rs;
    std::string p = "/home/luisa/Documenti/prova.txt";
    std::fstream CopiedF = rs.ReadFile(p);
    std::ifstream OriginF(p);
    char c;
    char d;
    while (OriginF.get(c) && CopiedF.get(d)) {
        ASSERT_EQ(c, d);
    }
}

TEST(ResourceLoader, TestNotify){
    ResourceLoader rs;
    auto pr=new ProgressBar(&rs);
    std::string p="/home/luisa/Documenti/prova2.txt";
    rs.notifyObservers();
    ASSERT_TRUE(rs.isNotified());
}

