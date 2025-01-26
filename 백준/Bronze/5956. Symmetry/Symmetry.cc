#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    while ((n & 1) && (m & 1)) {
        ans = ans * 4 + 1;
        n >>= 1;
        m >>= 1;
    }
    cout << ans;
}
