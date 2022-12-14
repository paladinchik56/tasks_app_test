#include "Task.h"
#include <iostream>
#include "Command.h"
#include "global_var.h"


Task::Task(std::string name, std::string description, tm date, std::string category): name(name), description(description),
                                                                                    date(date), category(category) {
}

std::string Task::get_name() {
    return name;
}

bool Task::set_done(bool state) {
    status = state;
    return status;
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


std::string Task::get_description() {
    return description;
}

tm Task::get_date() {
    return date;
}

std::string Task::get_category() {
    return category;
}

bool Task::get_status() {
    return status;
}

bool Task::valid_name(std::string name) {

    for (auto task: g_tasks) {
        if (task.get_name() == name) {
            cout << "task with name \"" << name << "\" already exist\n";
            return false;
        }
    }

    if (name.size() > MAX_TASK_NAME_SIZE) {
        std::cout << "The name of task can't be bigger than " << MAX_TASK_NAME_SIZE << std::endl;
        return false;
    }

    if (name.empty()) {
        cout << "name can't be empty\n";
        return false;
    }
    return true;
}

bool Task::valid_description(std::string description) {
    if (description.size() > MAX_DESCRIPTION_SIZE) {
        std::cout << "The name of task can't be bigger than " << MAX_DESCRIPTION_SIZE << std::endl;
        return false;
    }

    if (description.empty()) {
        cout << "name can't be empty\n";
        return false;
    }
    return true;
}

bool Task::valid_date(std::vector<std::string> splited_string) {
    if (splited_string[0].empty()) {
        cout << "date can't be empty\n";
        return false;
    }

    auto splited_date = string_split(splited_string[0], '-');

    time_t now = time(0);
    tm *ltm = localtime(&now);

    // check string for no valid symbols
    for (auto date: splited_date) {
        if (!is_number(date)) {
            cout << "invalid symbol in date" << std::endl;
            return false;
        }
    }

    //check years for valid
    if (1970 > stoi(splited_date[0]) || stoi(splited_date[0]) > (ltm->tm_year+1900)) {
        std::cout << "years should be between 1970 and " << ltm->tm_year+1900 << std::endl;
        return false;

    }

    // check months for valid
    if (0 > stoi(splited_date[1]) || stoi(splited_date[1]) > 12) {
        std::cout << "months should be between 01 and 12\n";
        return false;

    }

    // check days for valid
    // now this lazy check. todo refactor this
    if (0 > stoi(splited_date[2]) || stoi(splited_date[2]) > 31) {
        std::cout << "days should between 01 and 31\n";
        return false;
    }

    if (splited_string.size() == 2) {
        auto splited_time = string_split(splited_string[1], ':');

        // check string for invalid symbols
        for (auto time: splited_time) {
            if (!is_number(time)) {
                cout << "invalid symbol in time" << std::endl;
                return false;
                }
            }

        if (0 > stoi(splited_time[0]) || stoi(splited_time[0]) > 23) {
            cout << "hours should be between 00 and 24. yours: " << splited_time[0] << endl;
            return false;
        }

        if (0 > stoi(splited_time[1]) || stoi(splited_time[1]) > 59) {
            cout << "minutes should be between 00 and 60. yours: " << splited_time[1] << endl;
            return false;
        }
    }

    return true;
}

//std::vector<std::string> Task::field_task= {"name", "description","date", "category", "status"};

bool Task::valid_category(std::string category) {
    if (category.size() > MAX_CATEGORY_SIZE) {
        std::cout << "The name of task can't be bigger than " << MAX_CATEGORY_SIZE << std::endl;
        return false;
    }

    if (category.empty()) {
        cout << "name can't be empty\n";
        return false;
    }
    return true;
}

std::string Task::get_date_str() {
    return tm_to_string(date);
}

std::string Task::get_status_str() {
    if (status) return "done";
    return "undone";
}

const bool Task::check_field(const string &key) {
//    MyMap::const_iterator find = MyMap.task_fields.find(key);
    MyMap::const_iterator find = field_task.find(key);
    if (find != field_task.end()) {
        return true;
    }
    return false;
}

string Task::get_field_value(std::string const& field)
{
    field_task["name"] = name;
    field_task["description"] = description;
    field_task["date"] = tm_to_string(date);
    field_task["category"] = category;
    field_task["status"] = get_status_str();

    if (field == "") {
        return "";
    }
    MyMap::const_iterator find = field_task.find(field);
    if (find != field_task.end())
    {
        // If we find it return the field.
        return find->second;
    }

    cout << "field \"" + field + "\" doesn't exist\n";
    return "";
}


