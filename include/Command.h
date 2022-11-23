#ifndef TASKS_APP_COMMAND_H
#define TASKS_APP_COMMAND_H

#include <iostream>
#include <vector>
#include <string>
#include "global_var.h"
#include <bits/stdc++.h>
#include "Task.h"

class Command {
    std::string keyword;

protected:
    bool check_command_valid(std::string command);
    bool check_task_exist();

public:
    virtual bool check_valid() = 0;

    // A quick way to split strings separated via spaces.

    static std::vector<std::string> string_split(std::string str, char separator) {
        int startIndex = 0, endIndex = 0;
        std::vector<std::string> strings;

        for(int i=0;i <= str.size();i++)
        {
            if (str[i] == separator || i == str.size())
            {
                endIndex = i;
                string temp;
                temp.append(str, startIndex, endIndex - startIndex);
                strings.push_back(temp);
                startIndex = endIndex + 1;
            }
        }
        return strings;
    };
};

#endif //TASKS_APP_COMMAND_H
