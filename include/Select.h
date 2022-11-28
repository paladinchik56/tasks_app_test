#ifndef TASKS_APP_SELECT_H
#define TASKS_APP_SELECT_H

#include "Command.h"
#include <map>
#include <any>
#include <array>
//#include "Task.h"

class Task;
struct condition {
    std::string field;
    std::string select_operator;
    std::string value;
};


class Select: public Command {
    std::vector<Task> select_tasks;
    std::map<std::string, std::any> fields;
    std::vector<condition> analysis_select_string();
    std::array<std::string, 5> select_fields;

    bool check_task(condition req, Task task);
    bool check_valid() override;

    std::string delete_dbrackets(std::string val);
    std::string delete_comma(std::string val);

    bool check_fields();
public:

    bool select();
};
#endif //TASKS_APP_SELECT_H
