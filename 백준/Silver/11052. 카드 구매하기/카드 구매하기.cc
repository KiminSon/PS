#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, dp[10001] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dp[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
            dp[i] = max(dp[i], dp[i - j] + dp[j]);

    cout << dp[n];
}