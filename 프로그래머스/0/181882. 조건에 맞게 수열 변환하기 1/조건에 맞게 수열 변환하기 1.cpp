#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {

    for (int& num : arr) {
        if (!(num % 2) && num >= 50) {
            num /= 2;
        }
        else if(num%2 && num < 50){
            num *= 2;
        }
    }

    return arr;
}
