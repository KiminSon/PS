#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[10][10];
int team[10], p[10], visited[10];
int n, cnt = 2e9;

void dfs(int c) {
    for (int i = 0; i < n; i++) {
        if (!visited[i] && arr[c][i] == 1 && team[c] == team[i]) {
            visited[i] = 1;
            dfs(i);
        }
    }
}

void subset(int depth) {
    if (depth == n) {
        int r = -1, l = -1, rcnt = 0, lcnt = 0;
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            if (team[i] == 0) {
                r = i;
                rcnt += p[i];
            }
            if (team[i] == 1) {
                l = i;
                lcnt += p[i];
            }
        }
        if (r == -1 | l == -1) {
            return;
        }
        visited[r] = 1;
        visited[l] = 1;
        dfs(r);
        dfs(l);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                return;
            }
        }
        cnt = min(cnt, abs(rcnt - lcnt));
        return;
    }
    team[depth] = 1;
    subset(depth + 1);
    team[depth] = 0;
    subset(depth + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            arr[i][tmp - 1] = 1;
        }
    }
    subset(0);
    if (cnt == 2e9) {
        cnt = -1;
    }
    cout << cnt;
}
