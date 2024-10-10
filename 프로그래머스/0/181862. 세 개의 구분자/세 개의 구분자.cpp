#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;

    for (int i = 0; i < myStr.size(); ++i) {
        if ('a' == myStr[i] || 'b' == myStr[i] || 'c' == myStr[i]) {
            myStr[i] = ' ';
        }
    }
    std::stringstream stst(myStr);
    std::string str;
    stst << str;
    while (stst >> str) {
        answer.push_back(str);
    }
    if (!answer.size()) {
        answer.push_back("EMPTY");
    }
    return answer;
}