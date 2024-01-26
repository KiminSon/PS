#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[1001][10];
ll mod = 10007;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
            for (int k = j; k < 10; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    ll ans = 0;
    for (int i = 0; i < 10; i++)
        ans += dp[n][i];
    ans %= mod;
    cout << ans;
}