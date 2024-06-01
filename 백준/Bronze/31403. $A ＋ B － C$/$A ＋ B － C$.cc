#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << '\n';
    if (b == 1000)
        a *= 10000;
    else if (b >= 100)
        a *= 1000;
    else if (b >= 10)
        a *= 100;
    else
        a *= 10;
    cout << a + b - c;
}