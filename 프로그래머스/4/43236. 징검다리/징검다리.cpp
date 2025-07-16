#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <limits>
#include <algorithm>
using namespace std;


bool isPositive(std::vector<int>& _rocks, int _mid, int _PopCount, int _distance) {

    int leftRock = 0;
    int popCount = 0;
    for (int i : _rocks) {
        int distance = i  - leftRock;
        if (distance < _mid) {
            ++popCount;
            if (popCount > _PopCount) {
                return false;
            }
        }
        else {
            leftRock = i;
        }
    }

    if (_distance - leftRock < _mid) {
        ++popCount;
        if (popCount > _PopCount) {
            return false;
        }
    }


    return true;
}


int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    int left = 0;

    int right = distance;

    std::sort(rocks.begin(), rocks.end());

    if (rocks.size() == n) {
        return distance;
    }


    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isPositive(rocks, mid, n, distance) == false) {
            right = mid;  // mid거리로는 불가능 더 작은 거리로 일단 해봄
        }
        else {  // mid거리가 된다 -> 더 큰 거리로 시도해도 됨  그래서 mid를 제외
            left = mid + 1;
        }
    }


    return left - 1;  // mid값일때가 정답이어야하는데 left는 mid +1임 -1해줘야함
}

