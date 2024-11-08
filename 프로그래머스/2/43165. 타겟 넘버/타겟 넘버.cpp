#include <string>
#include <vector>
#include <queue>
using namespace std;

int result = 0;

void dfs(vector<int>& _vec, int _ref, int value, int target) {

    if (_vec.size() != _ref) {
        dfs(_vec, _ref + 1, value + _vec[_ref], target);
        dfs(_vec, _ref + 1, value - _vec[_ref], target);
    }

    if (target == value && _vec.size() == _ref) {
        ++result;
    }

}


int solution(vector<int> numbers, int target) {
    result = 0;

    std::queue<std::pair<int, int>> qu;
    std::pair<int, int> pa;
    qu.push(std::make_pair(numbers[0], 0));
    qu.push(std::make_pair(-numbers[0], 0));

    while(!qu.empty()){
        pa = qu.front();
        qu.pop();
        if (pa.second == numbers.size() - 1) {
            if (pa.first == target) {
                ++result;
            }
            continue;
        }
        qu.push(std::make_pair(numbers[pa.second + 1] + pa.first, pa.second + 1));
        qu.push(std::make_pair(- numbers[pa.second + 1] + pa.first, pa.second + 1));
    }

    return result;
}
