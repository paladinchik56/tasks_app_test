#include "Task.h"
#include <iostream>


Task::Task(std::string name, std::string description, tm date, std::string category): name(name), description(description),
                                                                                    date(date), category(category) {}

std::string Task::get_name() {
    return name;
}

bool Task::set_done(bool state) {
    done = state;
    return done;
};
