#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<vector<int> > adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            v[nxt]--;
            if (!v[nxt]) {
                q.push(nxt);
            }
        }
    }
}
