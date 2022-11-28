//
// Created by paladinchik56 on 11/23/22.
//

#include "Select.h"
#include <iostream>
#include <vector>
#include <string>
#include "global_var.h"
#include "Task.h"
#include <ctime>

#define MAX_SELECT_ARG 100

std::vector<condition> Select::analysis_select_string() {
    //clear before analyse
    select_fields = {};
    std::vector <condition> conditions;

    condition fields_operator_value;

    bool field_end = false;

    for (int i=1, field_i=0; i < g_input.size(); i++) {

        if (g_input[i] == "where" || g_input[i] == "and") {
            field_end = true;
            fields_operator_value.field = g_input[i + 1];
            fields_operator_value.select_operator = g_input[i + 2];

            // for date with time
            if (i+4 < g_input.size() && g_input[i+4] != "and") g_input[i+3] += " " + g_input[i + 4];
            fields_operator_value.value = delete_dbrackets(g_input[i + 3]);

            conditions.push_back(fields_operator_value);

            // this for don't check next if
            continue;
        }

        if (!field_end) {
            if (g_input[i] == "*") {
                select_fields[field_i++] = g_input[i];
                continue;
            }
            auto s = g_input[i];
            s = delete_comma(s);
            select_fields[field_i++] = s;
        }

    }

    return conditions;
}

bool Select::check_fields() {
    bool field_exist;
    // check for *
    if (select_fields[0] == "*") {
        select_fields = {"name", "description", "date", "category", "status"};
        return true;
    }

//    for (auto field: select_fields) {
//        field_exist = task.check_field(field);
//        if (!field_exist) {
//            cout << "field \"" << field << "doesn't exist\n";
//            return false;
//        }
//    }
    return true;
}

bool Select::check_task(condition req, Task task) {

   // switch doesn't work with string.

   // reflection the field type
   // name, description and cat have the same data type
   // comparisons operators need only in date.
   if (req.field == "date") {
       decltype(task.get_date()) field;
       field = string_to_tm(req.value);

       return compare_c_time_tm(field, task.get_date(), req.select_operator);
   }
   else if (req.field == "status") {
       decltype(task.get_status()) field;
       istringstream(req.value) >> std::boolalpha >> field;

       return field == task.get_status();
   }
   else {
       decltype(task.get_name()) field = req.value;
        std::string task_value;
       if (req.field == "name") task_value = task.get_name();
       if (req.field == "description") task_value = task.get_description();
       if (req.field == "category") task_value = task.get_category();

       // check like operator
       if (req.select_operator == "like") {
           if (task_value.find(field) != std::string::npos) return true;
           return false;
       }

        return field == task.get_name();
   }

   //todo write this error
    return false;
}

bool Select::select() {
    if (!check_command_arguments("select", MAX_SELECT_ARG)) return false;

    // check fields for select

    auto req_vector = analysis_select_string();

    if (!check_fields()) return false;

    std::vector<Task> select_tasks;

//    if (req_vector.empty()) {
//        for (auto task: g_tasks) cout << task.get_name() << endl;
//    }

    for (auto task: g_tasks) {
        bool good_task = req_vector.empty();
        for (auto req: req_vector) {
            if (!check_task(req, task)) break;
            good_task = true;
        }
        if (!good_task) continue;

        for (const auto& field:select_fields) {
            auto select_value = task.get_field_value(field);
            if (select_value == "") continue;
            cout << select_value << " ";
        }
        cout << endl;
        select_tasks.push_back(task);
    }



    return true;
}

bool Select::check_valid() {
    // here will check field words
    return false;
}

std::string Select::delete_dbrackets(std::string val) {
    return val.substr(1, val.size()-2);
}

std::string Select::delete_comma(std::string s) {
    if (s.find(',') != std::string::npos) s = s.substr(0, s.size()-1);
    return s;
}





