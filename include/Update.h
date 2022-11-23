#ifndef TASKS_APP_UPDATE_H
#define TASKS_APP_UPDATE_H

#include "Done.h"

class Update: public Command {
    bool check_valid() override;
public:

};

#endif //TASKS_APP_UPDATE_H
