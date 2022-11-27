#ifndef TASKS_APP_GLOBAL_VAR_H
#define TASKS_APP_GLOBAL_VAR_H

#include <string>
#include <vector>
#include <any>
#include <unordered_map>
#include "Task.h"

using namespace std;


extern map<string, any> g_commands;
extern vector<string> g_input;
extern vector<Task> g_tasks;

extern bool compare_c_time_tm(tm date1, tm date2, std::string str_operator);
tm string_to_tm(std::string str);
std::string tm_to_string(tm time_struct);
std::vector<std::string> string_split(std::string str, char separator);

#endif //TASKS_APP_GLOBAL_VAR_H
