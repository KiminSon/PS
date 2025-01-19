#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    while (cin >> n) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp = tmp * 10 + 1;
            tmp %= n;
            if (tmp == 0) {
                cout << i << '\n';
                break;
            }
        }
    }
}