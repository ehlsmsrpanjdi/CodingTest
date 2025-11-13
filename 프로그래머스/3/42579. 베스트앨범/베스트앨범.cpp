#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	std::unordered_map<string, int> typeMap;

	std::unordered_map<string, std::vector<std::pair<int, int>>> countMap;



	for (int i = 0; i < genres.size(); ++i) {
		typeMap[genres[i]] += plays[i];
		countMap[genres[i]].push_back(std::make_pair(plays[i], i));
	}

	std::vector<std::pair<std::string, int>> vec(typeMap.begin(), typeMap.end());


	std::sort(vec.begin(), vec.end(),
		[](const auto& a, const auto& b) {
			return a.second < b.second;
		});


	for (auto& pp : countMap) {
		std::sort(pp.second.begin(), pp.second.end(), [](auto& left, auto& right) {
			if (left.first == right.first) {
				return left.second < right.second;
			}
			return left.first > right.first;
			});
	}

	string str;
	std::vector<std::pair<int, int>> cachMap;

	std::vector<std::pair<int, int>>::iterator iter;

	for (int i = vec.size() - 1; i >= 0; --i) {
		str = vec[i].first;
		cachMap = countMap[str];
		iter = cachMap.begin();
		int count = 0;
		while (count != 2) {
			++count;
			answer.push_back((*iter).second);
			++iter;
			if (iter == cachMap.end()) {
				break;
			}
		}
	}


	return answer;
}