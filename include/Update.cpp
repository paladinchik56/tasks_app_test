#include "Update.h"

bool Update::check_valid() {
    if (!check_command_valid("update")) return false;
    return check_task_exist();
}
