#include <string>
#include <vector>
#include <map>
using namespace std;vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> count(4, 0);

	std::vector<int> student1 = { 1, 2, 3, 4, 5 };
	std::vector<int> student2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	std::vector<int> student3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int n = answers.size();


	int n1 = student1.size();
	int n2 = student2.size();
	int n3 = student3.size();

	for (int i = 0; i < n; i++) {
		int value = answers[i];
		if (student1[i % n1] == value) {
			++count[1];
		}

		if (student2[i % n2] == value) {
			++count[2];
		}

		if (student3[i % n3] == value) {
			++count[3];
		}
	}

	if (count[1] > count[2] && count[1] > count[3]) {
		answer.push_back(1);
	}
	else if (count[2] > count[1] && count[2] > count[3]) {
		answer.push_back(2);
	}
	else if (count[3] > count[1] && count[3] > count[2]) {
		answer.push_back(3);
	}
	else if (count[1] == count[2] && count[1] > count[3]) {
		answer.push_back(1);
		answer.push_back(2);
	}
	else if (count[1] == count[3] && count[1] > count[2]) {
		answer.push_back(1);
		answer.push_back(3);
	}
	else if (count[2] == count[3] && count[2] > count[1]) {
		answer.push_back(2);
		answer.push_back(3);
	}
	else if(count[1] == 0) {

	}
	else {
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(3);
	}



    return answer;
}
