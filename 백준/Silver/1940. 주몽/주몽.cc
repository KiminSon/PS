#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while (i != j) {
        if (v[i] + v[j] == m) {
            ans++;
            i++;
        } else if (v[i] + v[j] < m) {
            i++;
        } else {
            j--;
        }
    }
    cout << ans;
}
