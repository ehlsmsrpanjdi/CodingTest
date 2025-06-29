#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    //std::vector<std::pair<int, int>> vec;

    for (int i = 1; i * i<= yellow; ++i) {
        if (yellow % i == 0) {
            int carpetCount = yellow / i * 2 + i * 2 + 4;
            if (carpetCount == brown) {
                return { yellow / i + 2, i + 2 };
            }

            //vec.push_back(std::make_pair(yellow / i, i));
        }
    }


    return answer;
}
