#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10];



void fun(int _n) {

    if (_n == m) {
        for (int i = 0; i < m; ++i) {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (isused[i] != true) {
                arr[_n] = i;
                isused[i] = true;
                fun(_n + 1);
                isused[i] = false;
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fun(0);
}
