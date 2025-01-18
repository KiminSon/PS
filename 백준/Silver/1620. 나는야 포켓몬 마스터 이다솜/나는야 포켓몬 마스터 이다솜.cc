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
    vector<string> v(n);
    map<string, int> mp;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s] = i;
        v[i] = s;
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if ((int) s[0] < 58) {
            cout << v[stoi(s) - 1] << '\n';
        } else {
            cout << mp[s] + 1 << '\n';
        }
    }
}
