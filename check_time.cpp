#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void change(int& v) {
    v += 1;
}
int main() {
    // current date/time based on current system
    time_t now = time(0);

    cout << "Number of sec since January 1,1970:" << now << endl;

    tm *ltm = localtime(&now);

    tm t = tm();
    t.tm_year = 2022;
    // print various components of tm structure.
    cout << "Year" << t.tm_year;


    vector<int> vv = {1, 2, 3};
    int i = 0;

    for (int&  e: vv) {
//        change(vv[i]);
        change(e);
        i+=1;
    }
    for (auto e: vv) {
        cout << e << endl;
    }
}