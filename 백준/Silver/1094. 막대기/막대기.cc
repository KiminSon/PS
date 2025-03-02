#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int x, n = 64, cnt = 0;
    cin >> x;
    while (x > 0) {
        if (x >= n) {
            x -= n;
            cnt++;
        }
        n >>= 1;
    }
    cout << cnt;
}
