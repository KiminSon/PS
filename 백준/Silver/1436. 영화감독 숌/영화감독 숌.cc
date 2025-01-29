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
    int m = 665;
    int cnt = 0;
    while (cnt != n) {
        m++;
        string s = to_string(m);
        for (int i = 0; i < s.length() - 2; i++) {
            if (s[i] == '6' && s[i + 1] == s[i] && s[i + 2] == s[i]) {
                cnt++;
                break;
            }
        }
    }
    cout << m;
}
