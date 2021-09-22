#include "gtest/gtest.h"
#include "../ProgressBar.h"

TEST(ProgressBar, TestAttachDettach){
    ResourceLoader rs;
    auto pr=new ProgressBar(&rs);
    auto i=std::find(rs.getObservers().begin(), rs.getObservers().end(), pr);
    ASSERT_NE(i, rs.getObservers().end());
    pr->detach();
    auto j=std::find(rs.getObservers().begin(), rs.getObservers().end(), pr);
    ASSERT_EQ(j, rs.getObservers().end());
}

