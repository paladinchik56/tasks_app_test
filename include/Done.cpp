#include "Done.h"

bool Done::check_valid() {
    if (!check_command_arguments("status")) return false;
    return check_task_exist();
}

bool Done::done_task() {
    if (!check_valid()) {
        return false;
    }

    if (!check_task_exist()) {
        return false;
    }

//todo this is not DRY concept. do pointer for func
    for (auto task: g_tasks) {
        if (task.get_name() == g_input[1]) {
            task.set_done(true);
            cout << "the task with name " << task.get_name() << " is done\n";
            return true;
        }
    }
    return true;
}



