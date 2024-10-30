#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int index = x;
    while (n--) {
        answer.push_back(index);
        index += x;
    }
    return answer;
}
