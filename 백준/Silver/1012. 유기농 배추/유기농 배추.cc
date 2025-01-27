#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int m, n, k;
int arr[2501][2501] = {0,};
int visited[2501][2501] = {0,};
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > n || ny < 0 || ny > m || arr[nx][ny] == 0 || visited[nx][ny] == 1) {
            continue;
        }
        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> m >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}
