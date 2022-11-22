#include "Task.h"
#include <iostream>


Task::Task(std::string name, std::string description, tm date, std::string category): name(name), description(description),
                                                                                    date(date), category(category) {};
//Task::Task(std::vector<std::string> input_vector) {
//    Task::Task(input_vector[0], [1]);
//}
bool check_valid(std::vector<std::string> input_vector);
//bool Task::check_valid(std::vector<std::string> input_vector) {
//    if (input_vector[1].size() > MAX_TASK_NAME_SIZE) {
//        std::cout << "The name of task can't be bigger than " << MAX_TASK_NAME_SIZE << std::endl;
//        return false;
//    }
//    if (input_vector[2].size() > MAX_DESCRIPTION_SIZE) {
//        std::cout << "The description of task can't be bigger than " << MAX_DESCRIPTION_SIZE << std::endl;
//        return false;
//    }
//    if (input_vector[3].size() > MAX_DATE_SIZE) {
//        std::cout << "The description of task can't be bigger than " << MAX_DATE_SIZE << std::endl;
//        return false;
//    }
//    if (input_vector[4].size() > MAX_DATE_SIZE) {
//        std::cout << "The category of task can't be bigger than " << MAX_DATE_SIZE << std::endl;
//        return false;
//    }
//    return true;
//}