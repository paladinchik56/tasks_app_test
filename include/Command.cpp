#include "Command.h"

bool Command::check_command_valid(std::string command) {
    if (g_input.size() > 2) {
        cout << "command "<< command <<" done set only 1 argument. Example: "<< command << " taskname.\n";
        return false;
    }
    return true;
}

bool Command::check_task_exist() {
    auto taskname = g_input[1];
    for (auto task: g_tasks) {
        if (task.get_name() == g_input[1]) {
//            std::cout << "task with name '" << g_input[1] << "' is done\n";
            return true;
        }
    }
    std::cout << "task with name "<< taskname  << " doesn't exist\n";
    return false;
}