#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, k, m, s = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < k; i++) {
        s += v[i];
    }
    m = s;
    for (int i = k; i < n; i++) {
        s = s + v[i] - v[i - k];
        m = max(m, s);
    }
    cout << m;
}
