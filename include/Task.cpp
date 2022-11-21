#include "Task.h"

Task::Task() = delete;
Task::Task(std::string name, std::string description, time_t date, std::string category): name(name), description(description),
                                                                                    date(date), category(category) {};
