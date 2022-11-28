#include "Update.h"
#include "global_var.h"
#include <iostream>
#include <ctime>
#include "Task.h"


bool Update::check_valid() {
    if (!check_command_arguments("update")) return false;


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
        cout << "update is missed\n";
        return false;
    }
    cout << "the task was updated\n";
    return true;
}

bool Update::_update_task(Task& task) {
    char new_description[MAX_DESCRIPTION_SIZE];
    char new_date[MAX_DATE_SIZE];
    char new_category[MAX_CATEGORY_SIZE];


    cout << "new description: ";
    std::cin.getline(new_description, MAX_DESCRIPTION_SIZE);
    if (!Task::valid_description(new_description)) {
        cout << "description: \"" << new_description << "\" is not valid.\n";
        return false;
    }

    cout << "new date: ";

    std::cin.getline(new_date, MAX_DATE_SIZE);
    if (!Task::valid_date(string_split(new_date, ' '))) {
        cout << "date: \"" << new_description << "\" is not valid.\n";
        return false;
    }

    cout << "new category: ";
    std::cin.getline(new_category, MAX_CATEGORY_SIZE);
    if (!Task::valid_date(string_split(new_date, ' '))) {
        cout << "category: \"" << new_category << "\" is not valid.\n";
        return false;
    }

    task.set_description(new_description);
    task.set_category(new_category);

    tm new_time = string_to_tm(new_date);
    task.set_date(new_time);

    task.set_category(new_category);

    return true;
}