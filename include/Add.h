#ifndef TASKS_APP_ADD_H
#define TASKS_APP_ADD_H

#include "Command.h"
#include <vector>
#include <string>
#include "global_var.h"
#include <bits/stdc++.h>

class Add: public Command {

public:
    bool check_valid() override {
        if (g_input[1].size() > MAX_TASK_NAME_SIZE) {
            std::cout << "The name of task can't be bigger than " << MAX_TASK_NAME_SIZE << std::endl;
            return false;
        }
        if (g_input[2].size() > MAX_DESCRIPTION_SIZE) {
            std::cout << "The description of task can't be bigger than " << MAX_DESCRIPTION_SIZE << std::endl;
            return false;
        }
        if (g_input[3].size() > MAX_DATE_SIZE) {
            std::cout << "The date of task can't be bigger than " << MAX_DATE_SIZE << std::endl;
            return false;
        }

        //check date for valid
        auto splited_string = string_split(g_input[3], ' ');
        auto splited_date = string_split(splited_string[0], '-');

        time_t now = time(0);
        tm *ltm = localtime(&now);

        //check years for valid
        if (!(1970 < stoi(splited_date[0]) && stoi(splited_date[0]) < (ltm->tm_year+1901))) {
            std::cout << "years should be between 1970 and " << ltm->tm_year+1900 << std::endl;
        }

        // check months for valid
        if (!(0 < stoi(splited_date[1]) && stoi(splited_date[1]) < 13)) {
            std::cout << "months should be 01 and 12\n";
        }

        // check days for valid
        // now this lazy check. todo refactor this
        if (!(0 < stoi(splited_date[2]) && stoi(splited_date[1]) < 32)) {
            std::cout << "days should be 01 and 31\n";

            if (splited_string.size() == 2) {
                auto splited_time = string_split(splited_string[1], ':');
            }
        }

        if (splited_string.size() == 2) {
            auto splited_time = string_split(splited_string[1], ':');
        }


        if (g_input[4].size() > MAX_DATE_SIZE) {
            std::cout << "The category of task can't be bigger than " << MAX_DATE_SIZE << std::endl;
            return false;
        }
        return true;
    };
    bool add_task();
};

#endif //TASKS_APP_ADD_H
