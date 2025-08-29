#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <deque>

using namespace std;

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		std::sort(people.begin(), people.end(), [](std::vector<int>& _left, std::vector<int>& _right) {
			if (_left[0] > _right[0]) {
				return true;
			}

			else if (_left[0] == _right[0]) {
				if (_left[1] < _right[1]) {
					return true;
				}
			}

			return false;

			});


		std::vector<std::vector<int>> vec;

		int maxIndex = people.size();

		int currentIndex = 0;

		vec.push_back(std::vector<int>({ people[currentIndex][0], people[currentIndex][1] }));

		++currentIndex;

		while (currentIndex < maxIndex) {
			std::vector<std::vector<int>>::iterator iter = vec.begin();
			vec.insert(iter + people[currentIndex][1], std::vector<int>({ people[currentIndex][0], people[currentIndex][1] }));
			++currentIndex;
		}



		return vec;
	}
};
