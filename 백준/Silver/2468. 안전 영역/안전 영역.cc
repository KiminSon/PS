#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, ans = 1, water = 0;
int board[100][100];
bool visited[100][100];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (visited[x][y])
        return;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (board[nx][ny] < water)
            continue;
        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    while (1) {
        water++;
        int area = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && board[i][j] >= water) {
                    area++;
                    dfs(i, j);
                }

        if (area == 0)
            break;
        else
            ans = max(ans, area);
    }
    cout << ans;
}