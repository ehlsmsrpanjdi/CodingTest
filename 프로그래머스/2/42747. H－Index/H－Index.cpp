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

int solution(vector<int> citations) {
	int answer = 0;

	std::sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); ++i) {
		//  논문 인용횟수 >= 지금까지 본 논문개수
		if (citations[i] >= i + 1) {
			answer = i + 1;
		}
		else break;
	}


	return answer;
}