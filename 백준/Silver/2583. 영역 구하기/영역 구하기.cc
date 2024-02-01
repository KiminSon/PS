#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int m, n, k;
bool board[100][100];
bool visited[100][100];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int dfs(int r, int c) {
    if (visited[r][c])
        return 0;
    visited[r][c] = 1;

    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
            continue;
        if (visited[nr][nc] || board[nr][nc])
            continue;
        ret += dfs(nr, nc);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        for (int r = sy; r < ey; r++)
            for (int c = sx; c < ex; c++)
                board[r][c] = 1;
    }
    vector<int> ans;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (board[i][j] || visited[i][j])
                continue;
            ans.push_back(dfs(i, j));
        }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &i: ans)
        cout << i << ' ';
}