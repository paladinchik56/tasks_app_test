cmake_minimum_required(VERSION 3.23)
project(tasks_app)
#include(/opt/mongo/lib/cmake/libbsoncxx-3.7.0/libbsoncxx-config.cmake)
#include(/opt/mongo/lib/cmake/libmongocxx-3.7.0/libmongocxx-config.cmake)
#list(APPEND CMAKE_MODULE_PATH "${/opt/mongo}/cmake")

set(CMAKE_CXX_STANDARD 17)

add_library(task Task.cpp)
