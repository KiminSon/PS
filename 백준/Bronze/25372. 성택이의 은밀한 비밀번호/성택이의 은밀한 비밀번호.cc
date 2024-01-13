#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        if (s.size() >= 6 && s.size() <= 9)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}