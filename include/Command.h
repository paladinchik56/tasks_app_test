#ifndef TASKS_APP_COMMAND_H
#define TASKS_APP_COMMAND_H

#include <iostream>
#include <vector>
#include <string>
#include "global_var.h"
#include <bits/stdc++.h>
#include <array>

class Command {
    std::string keyword;
public:
    virtual bool check_valid(std::vector <std::string> input_vector) = 0;

    // A quick way to split strings separated via spaces.
 //todo do this func for check time in Task
    static std::array split(std::string s) {
        std::stringstream ss(s);
        std::string word;
        while (ss >> word) {
//        cout << word << endl;
            g_input.push_back(word);
        }
    }

};

#endif //TASKS_APP_COMMAND_H
