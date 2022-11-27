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

std::vector<request> Select::analysis_select_string() {

    std::vector <request> request_vector;

    request fields_operator_value;

    for (int i=0; i < g_input.size(); i++) {
        if (g_input[i] == "where" || g_input[i] == "and") {
            fields_operator_value.field = g_input[i + 1];
            fields_operator_value.select_operator = g_input[i + 2];

            // for date with time
            if (i+4 < g_input.size() && g_input[i+4] != "and") g_input[i+3] += " " + g_input[i + 4];
            fields_operator_value.value = delete_dbrackets(g_input[i + 3]);

            request_vector.push_back(fields_operator_value);
        }
    }

//    int batch_size  = 4;

    // check have string_split
//    if ((select_vector.size() - 3) % 3 ) batch_size = 3;
//    if ((select_vector.size() - 3) % 4) batch_size = 4;


//    // todo now it work only with *. do for all fields
//    if (select_vector.size() > 3) {
//    request req;
//        for (int i=3; i < select_vector.size(); i+=batch_size) {
//            req.field = select_vector[i];
//            req.select_operator = select_vector[i + 1];
//            req.value = select_vector[i + 2];
//            request_vector.push_back(req);
//        }
//    }


    return request_vector;
}


bool Select::check_task(request req, Task task) {

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


    auto req_vector = analysis_select_string();
    std::vector<Task> select_tasks;

    if (req_vector.empty()) {
        for (auto task: g_tasks) cout << task.get_name() << endl;
    }

    for (auto task: g_tasks) {
        bool good_task = false;
        for (auto req: req_vector) {
            if (!check_task(req, task)) break;
            good_task = true;
        }
        if (!good_task) continue;
        cout << task.get_name() << endl;
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





