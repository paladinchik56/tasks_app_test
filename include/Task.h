#ifndef TASKS_APP_TASK_H
#define TASKS_APP_TASK_H




#include <iostream>
#include <vector>
#include <map>
#include <any>
#include <string>
#include "Select.h"
//add name description date category

typedef std::map<std::string, std::string> MyMap;

class Task {
    friend class Select;
    std::string name;
    std::string description;
    tm date;
    std::string category;
    bool status = false;

    friend bool Select::select();

    MyMap field_task;
    static const Task myTask;


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
    std::string get_description();
    tm get_date();
    std::string get_date_str();
    std::string get_category();
    bool get_status();
    std::string get_status_str();





    bool set_done(bool state);
    bool set_name(std::string name);
    bool set_description(std::string description);
    bool set_date(tm date);
    bool set_category(std::string category);


    static bool valid_name(std::string name);
    static bool valid_description(std::string description);
    static bool valid_date(std::vector<std::string> splited_string);
    static bool valid_category(std::string category);

    const bool check_field(std::string const& key);

    std::string get_field_value(std::string const& field);
};

#endif //TASKS_APP_TASK_H
