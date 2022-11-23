#include "Update.h"
#include "global_var.h"
#include <iostream>
#include <ctime>

bool Update::check_valid() {
    if (!check_command_valid("update")) return false;
    auto taskname = g_input[1];
    for (auto task: g_tasks) {
        if (task.get_name() == g_input[1]) {
            return _update_task(&task);
        }
    }
}

bool Update::update_task() {
    if (!check_valid()) {
        return false;
    }

    return true;
}

bool Update::_update_task(Task* task) {
    char new_description[MAX_DESCRIPTION_SIZE];
    char new_date[MAX_DATE_SIZE];
    char new_category[MAX_CATEGORY_SIZE];

    std::cin.getline(new_description, MAX_DESCRIPTION_SIZE);
    std::cin.getline(new_date, MAX_DATE_SIZE);
    std::cin.getline(new_category, MAX_CATEGORY_SIZE);

    task->set_description(new_description);
    task->set_category(new_category);

    tm new_time = task->string_to_tm(new_date);
    task->set_date(new_time);

    task->set_category(new_category);

    return true;
}