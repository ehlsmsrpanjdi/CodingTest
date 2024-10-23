#include <string>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
	vector<int> answer;
	std::unordered_set<int> Mset;

	for (int i : arr) {
		if (Mset.find(i) == Mset.end()) {
			Mset.insert(i);
			answer.push_back(i);
		}
		if (answer.size() >= k) {
			return answer;
		}
	}

	while (answer.size() < k) {
		answer.push_back(-1);
	}

	return answer;
}
