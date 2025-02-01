#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
int visited[1001];
vector<int> v[1001];

void dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (!visited[v[x][i]]) {
            visited[v[x][i]] = 1;
            dfs(v[x][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}
