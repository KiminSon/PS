#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int l, p, v, tc = 1;
    cin >> l >> p >> v;
    while (l != 0 && p != 0 && v != 0) {
        cout << "Case " << tc << ": " << v / p * l + min(l, v % p) << '\n';
        tc++;
        cin >> l >> p >> v;
    }
}