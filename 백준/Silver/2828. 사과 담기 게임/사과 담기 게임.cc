#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, j, cnt = 0;
    cin >> n >> m >> j;
    int l = 1, r = m;
    for (int i = 0; i < j; i++) {
        int a;
        cin >> a;
        if (a > r) {
            cnt += a - r;
            l += a - r;
            r += a - r;
        }
        if (a < l) {
            cnt += l - a;
            r -= l - a;
            l -= l - a;
        }
    }
    cout << cnt;
}
