#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, mx = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &i: arr) {
        cin >> i;
        mx = max(i, mx);
    }
    int s = 0, e = mx, ans;
    ll sm;
    while (s <= e) {
        sm = 0;
        int mid = (s + e) / 2;
        for (auto &i: arr) {
            sm += max(i - mid, 0);
        }
        if (sm >= m) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << ans;
}
