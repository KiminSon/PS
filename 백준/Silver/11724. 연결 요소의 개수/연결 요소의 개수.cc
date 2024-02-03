#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> v[1001];
bool visited[1001] = {0,};

void dfs(int a) {
    visited[a] = 1;
    for (int i = 0; i < v[a].size(); i++) {
        int idx = v[a][i];
        if (visited[idx] == 0)
            dfs(idx);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (visited[i] == 0) {
            cnt++;
            dfs(i);
        }
    cout << cnt;
}