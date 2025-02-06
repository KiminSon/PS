#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char arr[50][50];
int n, m, cnt = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int i, int j) {
    int visited[n][m];
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            visited[i1][j1] = 0;
        }
    }
    visited[i][j] = 1;
    queue<pair<int, int> > q;
    q.push({i, j});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || arr[nx][ny] == 'W') {
                continue;
            }
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            cnt = max(visited[nx][ny], cnt);
            q.push({nx, ny});
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }
    cout << cnt - 1;
}
