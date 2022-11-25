#ifndef TASKS_APP_SELECT_H
#define TASKS_APP_SELECT_H

#include "Command.h"
#include <map>
#include <any>

struct request {
    std::string field;
    std::string select_operator;
    std::string value;
};


class Select: public Command {
    std::vector<Task> select_tasks;
    std::map<std::string, std::any> fields;
    std::vector<request> analysis_select_string();

    bool check_task(request req, Task task);
    bool check_valid() override;

public:

    bool select();
};
#endif //TASKS_APP_SELECT_H
