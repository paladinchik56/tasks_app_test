#ifndef TASKS_APP_COMMAND_H
#define TASKS_APP_COMMAND_H

#include <iostream>
#include <vector>
#include <string>
#include "global_var.h"
#include <bits/stdc++.h>

class Command {
    std::string keyword;

protected:
    bool check_command_arguments(std::string command, int max_num_arguments=1);
    bool check_task_exist();

public:
    virtual bool check_valid() = 0;

    // A quick way to split strings separated via spaces.

};

#endif //TASKS_APP_COMMAND_H
