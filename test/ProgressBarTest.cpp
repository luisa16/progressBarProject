#include "gtest/gtest.h"
#include "../ProgressBar.h"


TEST(ProgressBar, TestUpdate){
    ResourceLoader rs;
    auto pr=new ProgressBar(&rs);
    std::string p="/home/luisa/Documenti/prova2.txt";
    rs.notifyObservers();
    ASSERT_TRUE(pr->isUpdated());
}


