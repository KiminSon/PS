#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, s, ans = 0;
int arr[20];

void sol(int cur, int idx) {
    if (idx == n)
        return;
    if (cur + arr[idx] == s)
        ans++;
    sol(cur + arr[idx], idx + 1);
    sol(cur, idx + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sol(0, 0);
    cout << ans;
}