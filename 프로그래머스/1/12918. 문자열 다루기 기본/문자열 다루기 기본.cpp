#include <iostream>
#include <stdexcept>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int si = s.size();
    if (si == 4 || si == 6) {
        for (char c : s) {
            if (!isdigit(c)) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}