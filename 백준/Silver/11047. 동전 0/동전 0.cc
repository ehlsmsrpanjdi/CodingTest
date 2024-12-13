#include "functional"
#include "iostream"
using namespace std;

int n, k;
int a[15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = n - 1; i >= 0; --i) {
        if (k == 0) {
            break;
        }
        if (a[i] <= k) {
            ans += (k / a[i]);
            k = (k % a[i]);
        }
    }

    std::cout << ans;

    return 0;
}

