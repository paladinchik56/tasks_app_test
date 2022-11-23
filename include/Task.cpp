#include "Task.h"
#include <iostream>
#include "Command.h"


Task::Task(std::string name, std::string description, tm date, std::string category): name(name), description(description),
                                                                                    date(date), category(category) {}

std::string Task::get_name() {
    return name;
}

bool Task::set_done(bool state) {
    done = state;
    return done;
}

bool Task::set_name(std::string name) {
    this->name = name;
    return true;
}

bool Task::set_description(std::string description) {
    this->description = description;
    return true;
}

bool Task::set_date(tm date) {
    this->date = date;
    return true;
}

bool Task::set_category(std::string category) {
    this->category = category;
    return true;
}

tm Task::string_to_tm(std::string str) {

    auto splited_string = Command::string_split(str, ' ');
    std::vector<std::string> splited_date = Command::string_split(splited_string[0], '-');
    time_t now = time(0);
    tm *ltm = localtime(&now);
    tm new_date;

    new_date.tm_year = stoi(splited_date[0]);
    new_date.tm_mon= stoi(splited_date[1]);
    new_date.tm_mday = stoi(splited_date[2]);

    if (splited_string.size() == 2) {
        auto splited_time = Command::string_split(splited_string[1], ':');
        new_date.tm_hour =  stoi(splited_time[0]);
        new_date.tm_min =  stoi(splited_time[1]);

    }

    return new_date;
};
