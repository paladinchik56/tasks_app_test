#include "global_var.h"

#include <string>
#include <map>
#include <functional>
#include <string>
#include <any>
#include <vector>

std::unordered_map<std::string, std::any> g_commands;
std::vector<std::string> g_input;
std::vector<Task> g_tasks;

bool compare_c_time_tm(tm date1, tm date2, std::string str_operator) {

// todo can replace std::function for pointer on function for do code more faster
    std::map<std::string, std::function<bool(int, int)>> comparisons;
    comparisons["<"] = std::less<int>();
    comparisons[">"] = std::greater<int>();
    comparisons["<="] = std::less_equal<int>();
    comparisons[">="] = std::greater_equal<int>();
    comparisons["="] = std::equal_to<int>();

    if (str_operator=="<" || str_operator==">") {
        if (comparisons[str_operator](date2.tm_year, date1.tm_year)) return true;
        if (!comparisons["="](date2.tm_year, date1.tm_year)) return false;

        if (comparisons[str_operator](date2.tm_mon, date1.tm_mon)) return true;
        if (!comparisons["="](date2.tm_mon, date1.tm_mon)) return false;

        if (comparisons[str_operator](date2.tm_mday, date1.tm_mday)) return true;
        if (!comparisons["="](date2.tm_mday, date1.tm_mday)) return false;

        if (comparisons[str_operator](date2.tm_hour, date1.tm_hour)) return true;
        if (!comparisons["="](date2.tm_hour, date1.tm_hour)) return false;

        if (comparisons[str_operator](date2.tm_min, date1.tm_min)) return true;
        if (!comparisons["="](date2.tm_min, date1.tm_min)) return false;
    }

    if (!comparisons[str_operator](date2.tm_year, date1.tm_year)) return false;
    if (!comparisons[str_operator](date2.tm_mon, date1.tm_mon)) return false;
    if (!comparisons[str_operator](date2.tm_mday, date1.tm_mday)) return false;
    if (!comparisons[str_operator](date2.tm_hour, date1.tm_hour)) return false;
    if (!comparisons[str_operator](date2.tm_min, date1.tm_min)) return false;
    return true;
};
