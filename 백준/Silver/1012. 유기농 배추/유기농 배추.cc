#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, m, n, k;
bool arr[50][50];
bool visited[50][50];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

void reset() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            arr[i][j] = 0;
            visited[i][j] = 0;
        }
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if (arr[ny][nx] == 1 && visited[ny][nx] == 0)
            dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        reset();;
        while (k--) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j);
                    cnt++;
                }
        cout << cnt << '\n';
    }
}