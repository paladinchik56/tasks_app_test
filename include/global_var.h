#ifndef TASKS_APP_GLOBAL_VAR_H
#define TASKS_APP_GLOBAL_VAR_H

#define MAX_TASK_NAME_SIZE 30
#define MAX_DESCRIPTION_SIZE 1000
#define MAX_DATE_SIZE 17
#define MAX_CATEGORY_SIZE 30
#define MAX_COMMAND_SIZE (MAX_TASK_NAME_SIZE+MAX_DESCRIPTION_SIZE+MAX_DATE_SIZE+MAX_CATEGORY_SIZE)

#include <string>
#include <vector>
#include <any>
#include <unordered_map>
//#include "Task.h"
#include <map>

using namespace std;

class Task;

extern map<string, any> g_commands;
extern vector<string> g_input;
extern vector<Task> g_tasks;

extern bool compare_c_time_tm(tm date1, tm date2, std::string str_operator);
tm string_to_tm(std::string str);
std::string tm_to_string(tm time_struct);
std::vector<std::string> string_split(std::string str, char separator);

#endif //TASKS_APP_GLOBAL_VAR_H
