cmake_minimum_required(VERSION 3.20)
project(progressBarProject)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(progressBarProject main.cpp ResourceLoader.cpp ResourceLoader.h ProgressBar.cpp ProgressBar.h)
target_link_libraries(progressBarProject ${wxWidgets_LIBRARIES})
