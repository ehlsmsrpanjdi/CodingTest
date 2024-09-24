#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    for (char& c : my_string) {
        if (c == alp[0] || c == std::toupper(alp[0])) {
            c = std::toupper(alp[0]);
        }
        else {
            c = std::tolower(c);
        }
    }
    return my_string;
}