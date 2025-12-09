#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

bool func(int n, long long time, vector<int>& times) {
    long long total = 0;
    for (int t : times) {
        total += time / t;
        if (total >= n) return true;
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long left = 1;  // 반드시 1부터 시작
    long long right = (long long)*max_element(times.begin(), times.end()) * n;
    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (func(n, mid, times)) {
            answer = mid;     // 가능한 값 → 후보
            right = mid - 1;  // 더 작은 값 탐색
        } else {
            left = mid + 1;   // 불가능 → 더 큰 값 탐색
        }
    }

    return answer;
}