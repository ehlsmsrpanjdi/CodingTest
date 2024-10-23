#include <string>
#include <vector>

using namespace std;

bool divide(int value) {
	while (!(value % 2)) {
		value /= 2;
		if (value == 1) {
			return true;
		}
	}
	return false;
}


vector<int> solution(vector<int> arr) {
    if(arr.size() == 1){
        return arr;
    }
	while (!divide(arr.size())) {
		arr.push_back(0);
	}
	return arr;
}