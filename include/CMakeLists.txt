cmake_minimum_required(VERSION 3.22)
project(tasks_app)
file(GLOB cpp_files
        "*.cpp"
        "*.h"
        )

set(CMAKE_CXX_STANDARD 17)


add_library(task_lib STATIC ${cpp_files} Select.cpp Select.h)
