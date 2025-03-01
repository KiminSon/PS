#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int r, c, k, cnt;
char arr[5][5];
int visited[5][5];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int d) {
    if (d == k - 1) {
        if (x == 0 && y == c - 1) {
            cnt++;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] || arr[nx][ny] == 'T') {
            continue;
        }
        visited[nx][ny] = 1;
        dfs(nx, ny, d + 1);
        visited[nx][ny] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    visited[r - 1][0] = 1;
    dfs(r - 1, 0, 0);
    cout << cnt;
}
