
#include "Add.h"
#include <ctime>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "global_var.h"
#include "Task.h"



//bool Add::check_valid()
using namespace  std;

bool Add::add_task() {
        if (!check_valid()) {
            return false;
        }

        auto name = g_input[1];
        auto description = g_input[2];
        auto category = g_input[4];

        //check date_string with time or not
//        auto splited_data = this->string_split(g_input[3]);
        tm date = tm();

//check date for valid
// todo fix with time
    auto splited_string = string_split(g_input[3], ' ');
    auto splited_date = string_split(splited_string[0], '-');

    auto int_year = stoi(splited_date[0]);
    auto int_month = stoi(splited_date[1]);
    auto int_day = stoi(splited_date[2]);

    date.tm_year = int_year;
    date.tm_mon = int_month;
    date.tm_mday = int_day;


    //without this that fields save random digits
    date.tm_hour = -1;
    date.tm_min = -1;
    if (splited_string.size() == 2) {
        auto splited_time = string_split(splited_string[1], ':');
        auto int_hours = stoi(splited_time[0]);
        auto int_minutes = stoi(splited_time[1]);

        date.tm_hour = int_hours;
        date.tm_min = int_minutes;
    }

    Task task = Task(name, description, date, category);
    g_tasks.push_back(task);

    cout << "task with name - "<< name << " - was created\n";
        return true;
    }

bool Add::check_valid() {
    if (5 != g_input.size() && 6 != g_input.size()) {
        cout << "your data for add command not valid.\nshould be: add name description yyyy-mm-dd hh:mm (optional) category\n";
        return false;
    }

    if (!Task::valid_name(g_input[1])) return false;
//    if (g_input[1].size() > MAX_TASK_NAME_SIZE) {
//        std::cout << "The name of task can't be bigger than " << MAX_TASK_NAME_SIZE << std::endl;
//        return false;
//    }
    if (!Task::valid_description(g_input[2])) return false;
    if (g_input[2].size() > MAX_DESCRIPTION_SIZE) {
        std::cout << "The description of task can't be bigger than " << MAX_DESCRIPTION_SIZE << std::endl;
        return false;
    }


    // check, if input have time I will reconstruct here
    if (g_input.size() == 6) {
        g_input[3] += " " + g_input[4];
        g_input[4] = g_input[5];
        g_input.erase(g_input.begin() + 5);
    }

    //check date for valid
    if (g_input[3].size() > MAX_DATE_SIZE) {
        std::cout << "The date of task can't be bigger than " << MAX_DATE_SIZE << std::endl;
        return false;
    }

    auto splited_string = string_split(g_input[3], ' ');
    if (!Task::valid_date(splited_string)) return false;

    if (!Task::valid_category(g_input[4])) return false;

    return true;
}






// check format of date with time or not




