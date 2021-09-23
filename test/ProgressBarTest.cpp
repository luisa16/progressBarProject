#include "gtest/gtest.h"
#include "../ProgressBar.h"

TEST(ProgressBar, TestAttachDettach){
    ResourceLoader rs;
    auto pr=new ProgressBar(&rs);
    auto i=std::find(rs.getObservers().begin(), rs.getObservers().end(), pr);
    ASSERT_NE(i, rs.getObservers().end());
    //pr->detach();
    delete pr;
    auto j=std::find(rs.getObservers().begin(), rs.getObservers().end(), pr);
    ASSERT_EQ(j, rs.getObservers().end());
}

TEST(ProgressBar, TestUpdate){
    ResourceLoader rs;
    auto pr=new ProgressBar(&rs);
    std::string p="/home/luisa/Documenti/prova2.txt";
    rs.notifyObservers();
    ASSERT_TRUE(rs.isNotified());
    ASSERT_TRUE(pr->isUpdated());
}

/*TEST(ProgressBar, TestUpdate){
    ResourceLoader rs;
    auto pr=new ProgressBar(&rs);
    rs.ReadFile("/home/luisa/Documenti/prova2.txt");
    ASSERT_TRUE(pr->isUpdated());
}*/

