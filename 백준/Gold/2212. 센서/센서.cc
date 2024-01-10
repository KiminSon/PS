#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> v, dis;
    int n, k, ans = 0;
    cin >> n >> k;
    v.assign(n, 0);
    dis.assign(n - 1, 0);

    for (auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++)
        dis[i] = v[i + 1] - v[i];

    sort(dis.begin(), dis.end());

    for (int i = 0; i < n - k; i++)
        ans += dis[i];

    cout << ans;
}