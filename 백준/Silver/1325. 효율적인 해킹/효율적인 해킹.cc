#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> v[10001];
int visited[10001];
int n, m;

void re() {
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
}

int dfs(int x) {
    visited[x] = 1;
    int ret = 1;
    if (!v[x].size()) {
        return ret;
    }
    for (auto &i: v[x]) {
        if (!visited[i]) {
            ret += dfs(i);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    vector<pair<int, int> > ans;
    int mx = 0;
    for (int i = 0; i < m; i++) {
        int f, s;
        cin >> f >> s;
        v[s].push_back(f);
    }
    for (int i = 1; i <= n; i++) {
        re();
        int tmp = dfs(i);
        mx = max(mx, tmp);
        ans.push_back({tmp, i});
    }
    sort(ans.begin(), ans.end());
    for (auto &i: ans) {
        if (i.first == mx) {
            cout << i.second << ' ';
        }
    }
}
