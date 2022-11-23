cmake_minimum_required(VERSION 3.22)
project(tasks_app)
file(GLOB cpp_files
        "*.cpp"
        "*.h"
        )

set(CMAKE_CXX_STANDARD 17)


add_library(task_lib STATIC ${cpp_files} global_var.cpp Done.h Done.cpp Update.h Update.cpp Delete.h Delete.cpp)
#add_library(task_lib STATIC Add.cpp Task.cpp Command.cpp)
