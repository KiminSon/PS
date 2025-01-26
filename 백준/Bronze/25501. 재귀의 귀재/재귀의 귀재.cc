#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        string ss = s;
        reverse(s.begin(), s.end());
        if (s == ss) {
            cout << 1 << ' ' << s.size() / 2 + 1 << '\n';
        } else {
            cout << 0 << ' ';
            int cnt = 1;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ss[i]) {
                    cnt++;
                } else {
                    break;
                }
            }
            cout << cnt << '\n';
        }
    }
}
