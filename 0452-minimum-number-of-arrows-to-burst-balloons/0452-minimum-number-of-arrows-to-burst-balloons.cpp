#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {

		int answer = 1;

		if (points.size() == 1) {
			return 1;
		}

		std::sort(points.begin(), points.end(), [](std::vector<int>& _left, std::vector<int>& _right) {
			if (_left[1] < _right[1]) {
				return true;
			}
			else if (_left[1] == _right[1]) {
				if (_left[0] < _right[0]) {
					return true;
				}
				else {
					return false;
				}
			}
			else return false;
			});


		int minRight = points[0][1];


		for (std::vector<std::vector<int>>::iterator iter = points.begin(); iter != points.end();) {
			if (minRight >= (*iter)[0]) {
				++iter;
			}
			else {
				minRight = (*iter)[1];
				++iter;
				++answer;
			}
		}

		return answer;

	}
};