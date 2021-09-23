#include "gtest/gtest.h"
#include "../ResourceLoader.h"
#include "../ProgressBar.h"


TEST(ResourceLoader, TestConstructor) {
    ResourceLoader rs;
    ASSERT_EQ(0, rs.getFileSize());
    ASSERT_EQ("", rs.getFileName());
    ASSERT_FALSE(rs.isNotified());
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
    rs.ReadFile(p);
    ASSERT_TRUE(rs.isNotified());
}

