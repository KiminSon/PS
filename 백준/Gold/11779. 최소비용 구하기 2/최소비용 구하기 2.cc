#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int cur;
    ll cst;
};

bool operator <(pt a, pt b) {
    return a.cst > b.cst;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    ll arr[n + 1][n + 1];
    ll dist[n + 1];
    int prv[n + 1];
    for (int i = 1; i <= n; i++) {
        dist[i] = 9e18;
        for (int j = 1; j <= n; j++) {
            arr[i][j] = 9e18;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (arr[a][b] > c) {
            arr[a][b] = c;
        }
    }
    int sx, ex;
    cin >> sx >> ex;
    priority_queue<pt> q;
    q.push({sx, 0});
    dist[sx] = 0;
    while (q.size()) {
        auto [cur, cst] = q.top();
        q.pop();
        if (cst > dist[cur]) {
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (arr[cur][i] == 9e18) {
                continue;
            }
            if (cst + arr[cur][i] < dist[i]) {
                dist[i] = cst + arr[cur][i];
                q.push({i, cst + arr[cur][i]});
                prv[i] = cur;
            }
        }
    }
    cout << dist[ex] << '\n';
    vector<int> v;
    for (int i = ex; i != sx; i = prv[i]) {
        v.push_back(i);
    }
    v.push_back(sx);
    reverse(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto &i: v) {
        cout << i << ' ';
    }
}
