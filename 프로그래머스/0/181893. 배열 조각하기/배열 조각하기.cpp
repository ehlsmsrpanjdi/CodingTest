#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    int start = 0;
    int end = arr.size() -1;
    for (int i = 0; i < query.size(); ++i) {
        if(!(i%2)){
            end = query[i] + start;
        }
        else {
            start = query[i] + start;
        }
    }

    for (int i = start; i <= end; ++i) {
        answer.push_back(arr[i]);
    }

    return answer;
}