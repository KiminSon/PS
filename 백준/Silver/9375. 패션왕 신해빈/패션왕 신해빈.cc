#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        map<string, int> m;
        int n;
        cin >> n;
        while (n--) {
            string s, c;
            cin >> s >> c;
            if (m.find(c) == m.end())
                m.insert({c, 1});
            else
                m[c]++;
        }
        int a = 1;
        for (auto i: m)
            a *= (i.second + 1);
        a--;
        cout << a << '\n';
    }
}