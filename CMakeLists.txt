cmake_minimum_required(VERSION 3.20)
project(progressBarProject)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

#add_executable(${PROJECT_NAME} main.cpp ResourceLoader.cpp ResourceLoader.h MyFrame.cpp MyFrame.h Subject.h Observer.h)
add_executable(${PROJECT_NAME} main.cpp ResourceLoader.cpp ResourceLoader.h ProgressBar.cpp ProgressBar.h MyFrame.cpp MyFrame.h Subject.h Observer.h)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
