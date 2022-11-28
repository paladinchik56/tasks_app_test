#include "Delete.h"
#include "Task.h"



bool Delete::check_valid() {
    if (!check_command_arguments("delete")) return false;

    return check_task_exist();

}

bool Delete::delete_task() {
    if (!check_valid()) {
        return false;
    }

    if (!check_task_exist()) {
        return false;
    }

//todo this is not DRY concept. do pointer for func
    for (int i=0; i < g_tasks.size(); i++) {
        if (g_tasks[i].get_name() == g_input[1]) {
            g_tasks.erase(g_tasks.begin()+i);
            cout << "the task with name " << g_tasks[i].get_name() << " was deleted\n";
            return true;
        }
    }
    return true;
}