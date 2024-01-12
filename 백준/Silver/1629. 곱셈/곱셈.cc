#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A, B, c;

ll power(ll a, ll b) {
    if (b == 1)
        return a % c;
    ll tmp = power(a, b / 2) % c;
    if (b % 2 == 0)
        return (tmp * tmp) % c;
    else
        return ((((a % c) * tmp) % c) * tmp) % c;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> A >> B >> c;
    cout << power(A, B);
}