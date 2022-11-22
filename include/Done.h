#ifndef TASKS_APP_DONE_H
#define TASKS_APP_DONE_H

#include "Command.h"

class Done: public Command{
    bool check_valid() override;

public:
    bool done_task();
};
#endif //TASKS_APP_DONE_H
