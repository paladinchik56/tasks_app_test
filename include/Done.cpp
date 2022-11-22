#include "Done.h"

bool Done::check_valid() {

    for (auto task: g_tasks) {
        if (task.get_name() == g_input[1]) {
            task.set_done(true);
            std::cout << "task with name '" << g_input[1] << "' is done\n";
            return true;
        }
    }

    std::cout << "task with this name doesn't exist\n";
    return false;
}

bool Done::done_task() {
    if (!check_valid()) {
        return false;
    }

    return true;
}

