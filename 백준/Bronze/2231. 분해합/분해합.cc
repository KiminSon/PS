#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, s, p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        s = i;
        p = i;
        while (p) {
            s += p % 10;
            p /= 10;
        }
        if (n == s) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << endl;
}