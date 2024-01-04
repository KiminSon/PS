#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, ans = 0;
pair<int, int> w[101], b[101];

void sol(int i, int cur, int sum) {
    if (i == n) {
        ans = max(sum, ans);
        return;
    }
    if (cur + w[i + 1].first <= k)
        sol(i + 1, cur + w[i + 1].first, sum + w[i + 1].second);
    if (cur + b[i + 1].first <= k)
        sol(i + 1, cur + b[i + 1].first, sum + b[i + 1].second);
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
    sol(-1, 0, 0);
    cout << ans;
}