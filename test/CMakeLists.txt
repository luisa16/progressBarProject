cmake_minimum_required(VERSION 3.20)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})


set(SOURCE_FILES runAllTests.cpp ProgressBarTest.cpp ResourceLoaderTests.cpp)
add_executable(runProgressBarTests ${SOURCE_FILES})
target_link_libraries(runProgressBarTests ${GTEST_BOTH_LIBRARIES} ${wxWidgets_LIBRARIES} core)
