cmake_minimum_required(VERSION 3.22)
project(tasks_app)
#include(/opt/mongo/lib/cmake/libbsoncxx-3.7.0/libbsoncxx-config.cmake)
#include(/opt/mongo/lib/cmake/libmongocxx-3.7.0/libmongocxx-config.cmake)
#list(APPEND CMAKE_MODULE_PATH "${/opt/mongo}/cmake")
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_subdirectory(include)
link_directories(include)


add_executable(tasks_app main.cpp)
target_link_libraries(tasks_app task_lib)

