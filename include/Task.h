#ifndef TASKS_APP_TASK_H
#define TASKS_APP_TASK_H


#define MAX_TASK_NAME_SIZE 30
#define MAX_DESCRIPTION_SIZE 1000
#define MAX_DATE_SIZE 17
#define MAX_CATEGORY_SIZE 30
#define MAX_COMMAND_SIZE (MAX_TASK_NAME_SIZE+MAX_DESCRIPTION_SIZE+MAX_DATE_SIZE+MAX_CATEGORY_SIZE)

#include <iostream>
#include <vector>
#include "Command.h"
//add name description date category

class Task {
    std::string name;
    std::string description;
    tm date;
    std::string category;
    bool done = false;

public:
    Task() = delete;
    Task(std::string name, std::string description, tm date, std::string category);
//    Task(std::vector<std::string> input_vector);
    static bool check_valid(std::vector<std::string> input_vector) {
        if (input_vector[1].size() > MAX_TASK_NAME_SIZE) {
            std::cout << "The name of task can't be bigger than " << MAX_TASK_NAME_SIZE << std::endl;
            return false;
        }
        if (input_vector[2].size() > MAX_DESCRIPTION_SIZE) {
            std::cout << "The description of task can't be bigger than " << MAX_DESCRIPTION_SIZE << std::endl;
            return false;
        }
        if (input_vector[3].size() > MAX_DATE_SIZE) {
            std::cout << "The description of task can't be bigger than " << MAX_DATE_SIZE << std::endl;
            return false;
        }
        if (input_vector[4].size() > MAX_DATE_SIZE) {
            std::cout << "The category of task can't be bigger than " << MAX_DATE_SIZE << std::endl;
            return false;
        }
        return true;
    };

    std::string get_name();
    bool set_done(bool state);
    bool set_name(std::string name);
    bool set_description(std::string description);
    bool set_date(tm date);
    bool set_category(std::string category);

    tm string_to_tm(std::string str);
};

#endif //TASKS_APP_TASK_H
