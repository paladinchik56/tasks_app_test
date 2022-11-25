#ifndef TASKS_APP_DELETE_H
#define TASKS_APP_DELETE_H

#include "Done.h"

class Delete: private Command {
    bool check_valid() override;


public:
    bool delete_task();

};
#endif //TASKS_APP_DELETE_H
