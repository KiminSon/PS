#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    stack<int> s;
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cin >> m;
            s.push(m);
        } else if (n == 2) {
            if (s.empty())
                cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (n == 3) {
            cout << s.size() << '\n';
        } else if (n == 4) {
            if (s.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else {
            if (s.empty())
                cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
            }
        }
    }
}