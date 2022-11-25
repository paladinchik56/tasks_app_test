#include "Command.h"

bool Command::check_command_arguments(std::string command, int max_num_arguments) {
    if (g_input.size() == 1) {
        cout << "need arguments for command " << command << "\n";
        return false;
    }

    if (g_input.size() > max_num_arguments+1) {
        cout << "command "<< command <<" status set only " << max_num_arguments << " argument. Example: "<< command << " taskname.\n";
        return false;
    }
    return true;
}


bool Command::check_task_exist() {
    auto taskname = g_input[1];
    for (auto task: g_tasks) {
        if (task.get_name() == g_input[1]) {
//            std::cout << "task with name '" << g_input[1] << "' is status\n";
            return true;
        }
    }
    std::cout << "task with name "<< taskname  << " doesn't exist\n";
    return false;
}