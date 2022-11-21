#include <iostream>
#include <hash_map>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include "Task.h"
#include <any>

#define MAX_COMMAND_SIZE 1000

using namespace std;
unordered_map<string, any> g_commands;
vector<string> g_input;
vector<Task> g_tasks;

void func1() {
    cout << "func1 \n";
}

void add() {
    cout << "add \n ";
}


// A quick way to split strings separated via spaces.
void simple_tokenizer(string s) {
    stringstream ss(s);
    string word;
    while (ss >> word) {
//        cout << word << endl;
        g_input.push_back(word);
    }
}

int main(int argc, char const* argv[])
{

    g_commands["func1"] = func1;
    g_commands["add"] = add;

    char s[MAX_COMMAND_SIZE];



    while (true) {
        // read cin stream, split his and push_back strings in g_input for identificate command
        cin.getline(s, MAX_COMMAND_SIZE);
        simple_tokenizer(s);
        auto command = g_input[0];

        auto func = g_commands.find(command);
        if (func == g_commands.end()) {
            cout << "This command doesn't exist \n";
        }
        else {
            any_cast<void (*) ()> (func->second) ();
        }
        g_input.clear();
    }
}