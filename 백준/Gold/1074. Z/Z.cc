#include <iostream>
#include <cmath>
using namespace std;

int ZFun(int n, int r, int c) {
    if (n == 0) {
        return 0;
    }
    int half = std::pow(2, n - 1);
    int count;
    bool right = (c >= half);
    bool down = (r >= half);

    if ((right || down) == false) { //왼쪽 위  왼쪽 위면
        count = 0;
    }

    else if (right == true && down == false) { //오른쪽 위
        count = 1;
        c -= half;
    }

    else if (right == false && down == true) {  //왼쪽 아래
        count = 2;
        r -= half;
    }

    else {  //오른쪽 아래
        count = 3;
        c -= half;
        r -= half;
    }

    return count * half * half + ZFun(n - 1, r, c);
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    std::cout << ZFun(n, r, c);
    return 0;
}