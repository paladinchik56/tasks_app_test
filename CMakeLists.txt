cmake_minimum_required(VERSION 3.23)
project(tasks_app)
#include(/opt/mongo/lib/cmake/libbsoncxx-3.7.0/libbsoncxx-config.cmake)
#include(/opt/mongo/lib/cmake/libmongocxx-3.7.0/libmongocxx-config.cmake)
#list(APPEND CMAKE_MODULE_PATH "${/opt/mongo}/cmake")
message(STATUS ${CMAKE_MODULE_PATH})
find_package (mongoc-1.0 1.7 REQUIRED)


include_directories(include)
set(CMAKE_CXX_STANDARD 17)

add_executable(check check_time.cpp include/Add.cpp include/Command.cpp include/Command.h include/Add.h include/global_var.h)


add_executable(tasks_app main.cpp)
link_libraries(task_lib tasks_app)

