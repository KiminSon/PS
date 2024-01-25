#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, val[2][100001], dp[100001][3] = {0};
        cin >> n;
        for (auto &i: val)
            for (int j = 0; j < n; j++)
                cin >> i[j];

        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][0], max(dp[i][1], dp[i][2])));
            dp[i + 1][1] = max(dp[i + 1][1], max(dp[i][0], dp[i][2]) + val[0][i]);
            dp[i + 1][2] = max(dp[i + 1][2], max(dp[i][0], dp[i][1]) + val[1][i]);
        }

        cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
    }
}