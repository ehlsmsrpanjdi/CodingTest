#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;


string solution(string number, int k) {
	string answer = "";


	int max = 0;

	int index = 0;

	for (char c : number) {
		if (answer.empty() == true) {
			answer.push_back(c);
		}
		else if (answer.back() < c) {
			while (!answer.empty() && answer.back() < c && k > 0) {
				answer.pop_back();
				--k;
			}
			answer.push_back(c);
		}
		else {
			answer.push_back(c);
		}
	}

	while(k > 0){
		answer.pop_back();
		--k;
	}



	return answer;
}

