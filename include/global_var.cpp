#include "global_var.h"

#include <string>
#include <map>
#include <functional>
#include <string>
#include <any>
#include <vector>
#include "Task.h"

std::map<std::string, std::any> g_commands;
std::vector<std::string> g_input;
std::vector<Task> g_tasks;

bool compare_c_time_tm(tm date2, tm date1, std::string str_operator) {

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

std::vector<std::string> string_split(std::string str, char separator) {
    int startIndex = 0, endIndex = 0;
    std::vector<std::string> strings;

    for(int i=0;i <= str.size();i++)
    {
        if (str[i] == separator || i == str.size())
        {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return strings;
};


tm string_to_tm(std::string str) {

    auto splited_string = string_split(str, ' ');
    std::vector<std::string> splited_date = string_split(splited_string[0], '-');
    tm new_date;

    new_date.tm_year = stoi(splited_date[0]);
    new_date.tm_mon= stoi(splited_date[1]);
    new_date.tm_mday = stoi(splited_date[2]);

    new_date.tm_hour = -1;
    new_date.tm_min =  -1;

    if (splited_string.size() == 2) {
        auto splited_time = string_split(splited_string[1], ':');
        new_date.tm_hour =  stoi(splited_time[0]);
        new_date.tm_min =  stoi(splited_time[1]);

    }

    return new_date;
}

std::string tm_to_string(tm time_struct) {
    std::string str = to_string(time_struct.tm_year) + "-" + to_string(time_struct.tm_mon) + "-" + to_string(time_struct.tm_mday);
    // check if time was set
    if (time_struct.tm_hour != -1) {
        str += " " + to_string(time_struct.tm_hour) + ":" + to_string(time_struct.tm_min);
    }
    return str;
}