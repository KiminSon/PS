#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll t, s;
    cin >> t >> s;
    if (12 <= t && t <= 16 && s == 0)
        cout << 320;
    else
        cout << 280;
}