#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    int mn = 2000000;
    int mx = -2000000;
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (mx < tmp) mx = tmp;
        if (mn > tmp) mn = tmp;
    }
    cout << mn << ' ' << mx;
}
