#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, cur = -1, cnt = 0;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (auto &i: v) {
        cin >> i.second >> i.first;
    }
    sort(v.begin(), v.end());
    for (auto &i: v) {
        if (i.second >= cur) {
            cur = i.first;
            cnt++;
        }
    }
    cout << cnt;
}
