#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, a, b;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.emplace_back(b, a);
    }
    sort(v.begin(), v.end());
    int t = v[0].first;
    int c = 1;
    for (int i = 1; i < n; i++)
        if (t <= v[i].second) {
            c++;
            t = v[i].first;
        }
    cout << c;
}