#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, arr[21], ans = 1e9;
string s;

void f(int d) {
    if (d == n + 1) {
        int sum = 0;
        for (int i = 1; i <= 1 << (n - 1); i *= 2) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (arr[j] & i) {
                    cnt++;
                }
            }
            sum += min(cnt, n - cnt);
        }
        ans = min(ans, sum);
        return;
    }
    f(d + 1);
    arr[d] = ~arr[d];
    f(d + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int val = 1;
        for (auto &j: s) {
            if (j == 'T') {
                arr[i] |= val;
            }
            val *= 2;
        }
    }
    f(1);
    cout << ans;
}
