#include "Update.h"
#include "global_var.h"
#include <iostream>
#include <ctime>

bool Update::check_valid() {
    if (!check_command_valid("update")) return false;
    auto taskname = g_input[1];

    // not range-based in loop cause with range-based can't change the main val
//    for (int i=0; i<g_tasks.size(); ++i) {
    for (auto & g_task : g_tasks) {
        if (g_task.get_name() == g_input[1]) {
            return _update_task(g_task);
        }
    }
    cout << "task with name" << g_input[1] << "doesn't exist\n";
    return false;
}

bool Update::update_task() {
    if (!check_valid()) {
        return false;
    }

    return true;
}

bool Update::_update_task(Task& task) {
    char new_description[MAX_DESCRIPTION_SIZE];
    char new_date[MAX_DATE_SIZE];
    char new_category[MAX_CATEGORY_SIZE];

    std::cin.getline(new_description, MAX_DESCRIPTION_SIZE);
    std::cin.getline(new_date, MAX_DATE_SIZE);
    std::cin.getline(new_category, MAX_CATEGORY_SIZE);

    task.set_description(new_description);
    task.set_category(new_category);

    tm new_time = task.string_to_tm(new_date);
    task.set_date(new_time);

    task.set_category(new_category);

    return true;
}