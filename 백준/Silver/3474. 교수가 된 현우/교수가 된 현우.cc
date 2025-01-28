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
        ll n, m = 5, cnt = 0;
        cin >> n;
        while (1) {
            cnt += n / m;
            if (n / m == 0) {
                break;
            }
            m *= 5;
        }
        cout << cnt << '\n';
    }
}
