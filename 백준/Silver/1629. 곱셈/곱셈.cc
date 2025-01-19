#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b, c;

ll f(ll a, ll b) {
    if (b == 1) {
        return a % c;
    }
    ll tmp = f(a, b / 2);
    tmp = (tmp * tmp) % c;
    if (b % 2) {
        tmp = (tmp * a) % c;
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> a >> b >> c;
    cout << f(a, b);
}
