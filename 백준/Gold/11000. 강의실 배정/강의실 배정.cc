#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    v.assign(n, {0, 0});
    for (auto &i: v)
        cin >> i.first >> i.second;
    sort(v.begin(), v.end());

    pq.push(v[0].second);
    for (int i = 1; i < v.size(); i++) {
        if (v[i].first >= pq.top()) {
            pq.pop();
            pq.push(v[i].second);
        } else
            pq.push(v[i].second);
    }
    cout << pq.size();
}