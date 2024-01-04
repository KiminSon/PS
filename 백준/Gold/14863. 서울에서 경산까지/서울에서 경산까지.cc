#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, dp[101][100001];
pair<int, int> w[101], b[101];

int sol(int i, int t) {
    if (i == n)
        return 0;
    int &ret = dp[i][t];
    if (ret)
        return ret;
    ret = -1e9;
    if (t - w[i].first >= 0)
        ret = max(ret, sol(i + 1, t - w[i].first) + w[i].second);
    if (t - b[i].first >= 0)
        ret = max(ret, sol(i + 1, t - b[i].first) + b[i].second);
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w[i].first >> w[i].second >> b[i].first >> b[i].second;
    }
    cout << sol(0, k);
}