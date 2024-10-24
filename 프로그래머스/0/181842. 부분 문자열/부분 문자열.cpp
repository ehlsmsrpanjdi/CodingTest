#include <string>
#include <string.h>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    if (str2.find(str1) != -1) {
        answer = 1;
    }
    return answer;
}