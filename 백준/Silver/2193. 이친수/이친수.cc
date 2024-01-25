#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll dp[91] = {1, 1, 1};
    for (int i = 3; i < 91; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n];
}