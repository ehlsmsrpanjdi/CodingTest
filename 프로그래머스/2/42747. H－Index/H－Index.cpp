#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 1,1,1,1,2

int solution(vector<int> citations) {
    int answer = 0;

    std::sort(citations.begin(), citations.end(), std::greater<int>());

    int maxvalue = 0;
    int maxSize = citations.size();

    for (int i = 0; i < maxSize; ++i) {
        if (citations[i] >= i + 1) {
            maxvalue = i + 1;
        }
        else {
            break;
        }
    }
 


    return maxvalue;
}