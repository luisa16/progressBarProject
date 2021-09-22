cmake_minimum_required(VERSION 3.20)
project(progressBarProject)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})


set(SOURCE_FILES ProgressBar.cpp ProgressBar.h ResourceLoader.cpp ResourceLoader.h MyFrame.cpp MyFrame.h)
add_executable(${PROJECT_NAME} ResourceLoader.cpp ResourceLoader.h ProgressBar.cpp ProgressBar.h MyFrame.cpp MyFrame.h Subject.h Observer.h)
# add_executable(progressBarProject main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(progressBarProject ${wxWidgets_LIBRARIES} core)
