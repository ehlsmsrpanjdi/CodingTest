#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool func(int n, long long time, vector<int>& times) {
    long long totalCnt = 0;
    for (int i : times) {
        totalCnt += time / i;
        if (totalCnt >= n) return true;  // 오버플로우 방지
    }
    return totalCnt >= n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1;
    long long maxValue = (long long)*max_element(times.begin(), times.end());
    long long right = (long long)n * maxValue;
    
    while (left <= right) {  // <= 사용
        long long mid = (left + right) / 2;  // 내림
        
        if (func(n, mid, times)) {  // mid 시간에 n명 처리 가능?
            answer = mid;
            right = mid - 1;  // 더 작은 시간 탐색
        } else {
            left = mid + 1;  // 더 큰 시간 필요
        }
    }
    
    return answer;
}