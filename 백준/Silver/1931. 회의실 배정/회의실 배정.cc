#include "functional"
#include "iostream"
#include "algorithm"
using namespace std;


int n;
struct Meeting {
	int start, end;
};

bool compare(const Meeting& a, const Meeting& b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;


	vector<Meeting> meetings(n);

	for (int i = 0; i < n; i++) {
		cin >> meetings[i].start >> meetings[i].end;
	}

	std::sort(meetings.begin(), meetings.end(), compare);

	int right = meetings[0].end;
	int answer = 1;
	for (int i = 1; i < n; ++i) {
		if (meetings[i].start >= right) {
			++answer;
			right = meetings[i].end;
		}
	}

	std::cout << answer;

	return 0;
}

