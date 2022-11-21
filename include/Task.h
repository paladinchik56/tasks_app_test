#ifndef TASKS_APP_TASK_H
#define TASKS_APP_TASK_H
#include <iostream>

//add name description date category

class Task {
    std::string name;
    std::string description;
    time_t date;
    std::string category;

public:
    Task();
    Task(std::string name, std::string description, time_t date, std::string category);
};

#endif //TASKS_APP_TASK_H
