#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, cost[101], dp[101][10001];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 1e9;

    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
        for (int j = 0; j <= k; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            int l = j + cost[i];
            if (l <= k)
                dp[i][l] = min(dp[i][l], dp[i][j] + 1);
        }
    }

    if (dp[n - 1][k] == 1e9)
        cout << -1;
    else
        cout << dp[n - 1][k];
}