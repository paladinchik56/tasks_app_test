#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // current date/time based on current system
    time_t now = time(0);

    cout << "Number of sec since January 1,1970:" << now << endl;

    tm *ltm = localtime(&now);

    tm t = tm();
    t.tm_year = 2022;
    // print various components of tm structure.
    cout << "Year" << t.tm_year;
}