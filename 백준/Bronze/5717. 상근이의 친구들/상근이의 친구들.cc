#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    while (1) {
        int n, m;
        cin >> n >> m;
        if (!n && !m) {
            break;
        }
        cout << n + m << '\n';
    }
}
