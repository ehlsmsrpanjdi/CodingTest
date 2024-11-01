#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int ssize = s.size();
    if (!(ssize % 2)) {
        answer += s[ssize / 2 - 1];
        answer += s[ssize / 2];
    }
    else {
        answer += s[ssize / 2];
    }
    return answer;
}
