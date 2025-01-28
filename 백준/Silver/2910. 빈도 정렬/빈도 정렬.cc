#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<int, int> > v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
        if (mp_first[tmp] == 0) {
            mp_first[tmp] = i + 1;
        }
    }
    for (auto it: mp) {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i: v) {
        for (int j = 0; j < i.first; j++) {
            cout << i.second << ' ';
        }
    }
}
