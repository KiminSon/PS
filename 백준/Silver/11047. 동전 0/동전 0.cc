#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int a[11];
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = 0;
    for (int i = n - 1; i >= 0; i--) {
        s += t / a[i];
        t = t % a[i];
    }
    cout << s;
}