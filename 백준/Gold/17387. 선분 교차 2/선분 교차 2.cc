#include <iostream>
#include <algorithm>
using namespace std;

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long result = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (result > 0) return 1;
    if (result < 0) return -1;
    return 0;
}

int main() {
    long long x1, y1, x2, y2;
    long long x3, y3, x4, y4;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    long long ccw1 = CCW(x1, y1, x2, y2, x3, y3);
    long long ccw2 = CCW(x1, y1, x2, y2, x4, y4);
    long long ccw3 = CCW(x3, y3, x4, y4, x1, y1);
    long long ccw4 = CCW(x3, y3, x4, y4, x2, y2);
    
    // 기본 교차 조건
    if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
        // 일직선인 경우 범위 체크
        if (ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0) {
            if (min(x1,x2) <= max(x3,x4) && min(x3,x4) <= max(x1,x2) &&
                min(y1,y2) <= max(y3,y4) && min(y3,y4) <= max(y1,y2)) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else {
            cout << 1;
        }
    } else {
        cout << 0;
    }
    
    return 0;
}