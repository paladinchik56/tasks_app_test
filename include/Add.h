#ifndef TASKS_APP_ADD_H
#define TASKS_APP_ADD_H

#include "Command.h"


class Add: virtual public Command {

public:
    bool check_valid(std::vector<std::string> input_vector) override;
};

#endif //TASKS_APP_ADD_H
