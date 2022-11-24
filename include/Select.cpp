//
// Created by paladinchik56 on 11/23/22.
//

#include "Select.h"
#include <iostream>
#include <vector>
#include <string>
#include "global_var.h"
#include <bits/stdc++.h>
#include "Task.h"
#include <ctime>
#include <boost/date_time.hpp>


std::vector<request> Select::analysis_select_string(std::string select_string) {
    std::vector <std::string> field_condition_operator = string_split(select_string, ' ');
    std::vector <request> request_vector;

    // todo now program can understand only data with time format: yyyy-mm-dd. NEED DO FOR  yyyy-mm-dd hh:mm
    int batch_size  = 4;

    // check have string_split
//    if ((field_condition_operator.size() - 3) % 3 ) batch_size = 3;
//    if ((field_condition_operator.size() - 3) % 4) batch_size = 4;


    // todo now it work only with *. do for all fields
    if (field_condition_operator.size() > 3) {
    request req;
        for (int i=3; i < field_condition_operator.size(); i+=batch_size) {
            req.field = field_condition_operator[i];
            req.select_operator = field_condition_operator[i+1];
            req.value = field_condition_operator[i+2];
            request_vector.push_back(req);
        }
    }


    return request_vector;
}


bool Select::check_task(request req, Task task) {

   // switch doesn't work with string..

   // reflection the field type
   // name, description and cat have the same data type
   if (req.field == "date") {
       decltype(task.get_date()) field;
       field = Task::string_to_tm(req.value);

       if (field == task.get_date())
   }
   else if (req.field == "status") {
       decltype(task.get_status()) field;
       istringstream(req.value) >> std::boolalpha >> field;
   }
   else  {
       decltype(task.get_name()) field = req.value;

   }

    return false;
}



