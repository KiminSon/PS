#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        int l = 0;
        int r = s.size() - 1;
        bool f = 1;
        for (; l <= r; l++, r--) {
            cnt++;
            if (s[l] != s[r]) {
                f = 0;
                break;
            }
        }
        cout << (f ? 1 : 0) << ' ' << (f && s.size() % 2 == 0 ? cnt + 1 : cnt) << '\n';
    }
}