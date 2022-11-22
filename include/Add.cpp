
#include "Add.h"
#include <ctime>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "global_var.h"



//bool Add::check_valid()

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
    auto splited_string = string_split(g_input[3], ' ');
    auto splited_date = string_split(splited_string[0], '-');

    auto int_year = stoi(splited_date[0]);
    auto int_month = stoi(splited_date[1]);
    auto int_day = stoi(splited_date[2]);

    date.tm_year = int_year;
    date.tm_mon = int_month;
    date.tm_mday = int_day;

    if (splited_string.size() == 2) {
        auto splited_time = string_split(splited_string[1], ':');
        auto int_hours = stoi(splited_time[0]);
        auto int_minutes = stoi(splited_time[1]);

        date.tm_hour = int_hours;
        date.tm_min = int_minutes;
    }

    Task task = Task(name, description, date, category);
    g_tasks.push_back(task);

        return true;
    }



    // check format of date with time or not




