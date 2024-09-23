#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    int i = 0;
    while (n >= answer) {
        answer += numbers[i++];
    }

    return answer;
}
