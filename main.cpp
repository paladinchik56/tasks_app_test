#include <iostream>
#include <ctime>
#include <stdio.h>

#include "Task.h"
#include <any>
#include <vector>
#include "Add.h"
#include "Done.h"
#include "Update.h"
#include "Select.h"
#include <global_var.h>
#include <Delete.h>
#include <Update.h>


using namespace std;
extern vector<Task> g_tasks;


//void add() {
//
//    // check size of general input and every element
//    if (g_input.size() > 6) {
//        cout << "You write to much info.\n Program can work only with string not bigger than " <<endl;
//        return;
//    }
//
//    switch (g_input.size()) {
//        case 6:
//            g_input[3] += " " + g_input[4];
//            g_input[4] = g_input[5];
//            g_input.pop_back();
//        case 5:
//            if (Task::check_valid(g_input)) {
//                cout << "checker \n";
//            }
//            break;
//
//
//    }
//
//
//
//    cout << "add \n";
//}


// A quick way to split strings separated via spaces.
void simple_tokenizer(string s) {
    stringstream ss(s);
    string word;
    while (ss >> word) {
//        cout << word << endl;
        g_input.push_back(word);
    }
}

//block commands
Add add;
Done done;
Delete delete1;
Update update;
Select select1;

void add_handler() {
    add.add_task();
}

void done_handler() {
    done.done_task();
}

void delete_handler() {
    delete1.delete_task();
}

void update_handler() {
    update.update_task();
}

void select_handler() {
    select1.select();
}

int main(int argc, char const* argv[])
{
    g_commands["add"] = add_handler;
    g_commands["done"] = done_handler;
    g_commands["delete"] = delete_handler;
    g_commands["update"] = update_handler;
    g_commands["select"] = select_handler;
    g_commands["Select"] = select_handler;

    char s[MAX_COMMAND_SIZE];

    while (true) {
        // read cin stream, split his and push_back strings in g_input for identificate command
        g_input.clear();
        cin.clear();
        cin.getline(s, MAX_COMMAND_SIZE);

        simple_tokenizer(s);
        if (g_input.empty()) continue;
        auto command = g_input[0];
        if (command == "exit") {
            return 0;
        }

        auto func = g_commands.find(command);

        if (func == g_commands.end()) {
            cout << "This command doesn't exist \n";
        }
        else {
            any_cast<void (*) ()> (func->second) ();
        }

    }
}