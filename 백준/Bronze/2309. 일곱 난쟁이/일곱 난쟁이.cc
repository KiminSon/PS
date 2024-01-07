#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> v(9);
    int ans = 0, a, b;
    for (auto &i: v) {
        cin >> i;
        ans += i;
    }
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 9; j++)
            if (v[i] + v[j] == ans - 100) {
                a = i;
                b = j;
            }
    v[a] = 101;
    v[b] = 101;
    sort(v.begin(), v.end());
    v.erase(v.begin() + 7, v.end());
    for (auto &i: v)
        cout << i << '\n';
}