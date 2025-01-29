#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, cnt = 0;
vector<vector<int> > v;

void dfs(int x) {
    if (x == m) {
        return;
    }
    if (!v[x].size() || v[x].size() == 1 && v[x][0] == m) {
        cnt++;
        return;
    }
    for (auto &i: v[x]) {
        dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    int r;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == -1) {
            r = i;
        } else {
            v[tmp].push_back(i);
        }
    }
    cin >> m;
    dfs(r);
    cout << cnt;
}
