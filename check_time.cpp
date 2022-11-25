#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <functional>

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

    std::map<std::string, std::function<bool(int, int)>> comparisons;
    comparisons["<"] = std::less<int>();
    comparisons[">"] = std::greater<int>();
    comparisons["<="] = std::less_equal<int>();
    comparisons[">="] = std::greater_equal<int>();
    comparisons["="] = std::equal_to<int>();
    vector<int> vv;
    int i = 0;

    cout << comparisons["<"](1, 2) << endl;

    for (i; i < 10; i++) vv.push_back(i);


    for (auto e: vv) {
    }

    string val = "\"cat\"";
    cout << val << endl << val.substr(1, val.size()-2);

}