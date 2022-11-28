#ifndef TASKS_APP_ADD_H
#define TASKS_APP_ADD_H

#include "Command.h"
#include <vector>
#include <string>
#include "global_var.h"
#include <bits/stdc++.h>

class Add: public Command {
public:
    bool check_valid() override;
    bool add_task();
};

#endif //TASKS_APP_ADD_H
