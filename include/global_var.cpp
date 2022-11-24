#include "global_var.h"

#include <string>
#include <map>
#include <functional>
using namespace std;
unordered_map<string, any> g_commands;
vector<string> g_input;
vector<Task> g_tasks;

bool compare_c_time_tm(tm date1, tm date2, std::string str_operator) {

// todo can replace std::function for pointer on function for do code more faster
    std::map<std::string, std::function<bool(int, int)>> comparisons;
    comparisons["<"] = std::less<int>();
    comparisons[">"] = std::greater<int>();
    comparisons["<="] = std::less_equal<int>();
    comparisons[">="] = std::greater_equal<int>();
    comparisons["="] = std::equal_to<int>();


    if (str_operator=="<" || str_operator==">") {

    }

    if (!comparisons[str_operator](date1.tm_year, date2.tm_year)) return false;
    if (!comparisons[str_operator](date1.tm_mon, date2.tm_mon)) return false;
    if (!comparisons[str_operator](date1.tm_mday, date2.tm_mday)) return false;
    if (!comparisons[str_operator](date1.tm_hour, date2.tm_hour)) return false;
    if (!comparisons[str_operator](date1.tm_min, date2.tm_min)) return false;
    return true
};
