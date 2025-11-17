#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;


int solution(string begin, string target, vector<string> words) {
	std::vector<bool> isVisited = vector<bool>(words.size(), false);

	std::queue<std::pair<string, int>> qu;


	qu.push(make_pair(begin, 0));

	while (!qu.empty()) {
		std::pair<string, int> pa = qu.front();
		qu.pop();

		for (int i = 0; i < words.size(); ++i) {
			if (isVisited[i] == true) {
				continue;
			}
			const string& str = words[i];  //단어받아오고
			int count = 0;					//몇개틀렸는지확인용
			for (int j = 0; j < str.size(); ++j) {  // element랑 몇 개 틀린지 확인해보기
				if (pa.first[j] != str[j]) {
					++count;
					if (count > 1) {  //두 개 이상이면 애초에 안됨
						break;
					}
				}
			}
			if (count == 1) {   //한 개면 집어느
				if (str == target) {
					return pa.second + 1;
				}
				qu.push(make_pair(str, pa.second + 1));
				isVisited[i] = true;
			}
		}
	}

	return 0;
}
