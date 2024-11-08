#include <string>
#include <vector>
#include <queue>
#include <stack>
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
    int dfsresult = 0;
    std::queue<std::pair<int, int>> qu;
    std::stack<std::pair<int, int>> st;
    std::pair<int, int> pa;
    qu.push(std::make_pair(numbers[0], 0));
    qu.push(std::make_pair(-numbers[0], 0));

    st.push(std::make_pair(numbers[0], 0));
    st.push(std::make_pair(-numbers[0], 0));

    //while(!qu.empty()){
    //    pa = qu.front();
    //    qu.pop();
    //    if (pa.second == numbers.size() - 1) {
    //        if (pa.first == target) {
    //            ++result;
    //        }
    //        continue;
    //    }
    //    qu.push(std::make_pair(numbers[pa.second + 1] + pa.first, pa.second + 1));
    //    qu.push(std::make_pair(- numbers[pa.second + 1] + pa.first, pa.second + 1));
    //}

    while (!st.empty()) {
        pa = st.top();
        st.pop();
        if (pa.second == numbers.size() - 1) {
            if (pa.first == target) {
                ++result;
            }
            continue;
        }
        st.push(std::make_pair(numbers[pa.second + 1] + pa.first, pa.second + 1));
        st.push(std::make_pair(-numbers[pa.second + 1] + pa.first, pa.second + 1));
    }


    return result;
}