#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
	sort(num_list.begin(), num_list.end());
	std::vector<int> vec(num_list.begin() + 5, num_list.end());
	return vec;
}