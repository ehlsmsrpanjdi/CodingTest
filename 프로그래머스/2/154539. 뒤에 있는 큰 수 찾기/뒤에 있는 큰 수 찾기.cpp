#include <string>
#include <list>
#include <vector>
#include <map>
#include <stack>

using namespace std;
vector<int> solution(vector<int> numbers) {
	

	std::stack<int> s;
	std::stack<int> aaa;

	std::list<int> li;

	std::stack<int> ans;
	

	for (int i = 0; i < numbers.size(); ++i) {
		s.push(numbers[i]);
	}

	while (s.empty() != true) {
		if (aaa.empty() == true) {
			aaa.push(s.top());
			li.push_front(-1);
			s.pop();
		}
		else {
			if (aaa.top() <= s.top()) {
				aaa.pop();
			}
			else {
				li.push_front(aaa.top());
				aaa.push(s.top());
				s.pop();
			}
		}
	}

	vector<int> answer(li.begin(), li.end());
	
	return answer;
}