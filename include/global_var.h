#ifndef TASKS_APP_GLOBAL_VAR_H
#define TASKS_APP_GLOBAL_VAR_H

#include <string>
#include <vector>
#include <any>
#include <unordered_map>
#include "Task.h"

using namespace std;
extern unordered_map<string, any> g_commands;
extern vector<string> g_input;
extern vector<Task> g_tasks;


#endif //TASKS_APP_GLOBAL_VAR_H
