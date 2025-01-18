#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    map<string, int> ms;
    map<int, string> mi;
    int n, m;
    string s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        ms.insert({s, i});
        mi.insert({i, s});
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if ((int) s[0] < 58)
            cout << mi[stoi(s)] << '\n';
        else
            cout << ms[s] << '\n';
    }
}
