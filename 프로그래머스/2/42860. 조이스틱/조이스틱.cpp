#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int n = name.size();
    int answer = 0;

    for (char c : name) {
        answer += min(c - 'A', 'Z' - c + 1);
    }

    int move = n - 1; // 기본: 끝까지 직진
    for (int i = 0; i < n; i++) {
        int next = i + 1;
        while (next < n && name[next] == 'A') next++;

        move = min(move, i + n - next + min(i, n - next));
    }

    answer += move;
    return answer;
}
