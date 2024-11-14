#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;  // a, b, c를 입력 받음
    long long result = 1;
    a = a % c;  // a를 c로 나눈 나머지를 구해서 a를 갱신

    while (b > 0) {
        if (b % 2 == 1) {  // b가 홀수일 때
            result = (result * a) % c;  // result에 a를 곱한 후 c로 나눈 나머지
        }
        a = (a * a) % c;  // a를 제곱한 후 c로 나눈 나머지를 갱신
        b /= 2;  // b를 반으로 줄임
    }

    cout << result << endl;  // 결과 출력
    return 0;
}