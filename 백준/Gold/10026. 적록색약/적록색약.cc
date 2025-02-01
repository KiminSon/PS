#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, cnt = 0;
char rgb[100][100];
bool visited[100][100] = {0,};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (!visited[nx][ny] && rgb[x][y] == rgb[nx][ny])
            dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rgb[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
    cout << cnt << ' ';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
            if (rgb[i][j] == 'G')
                rgb[i][j] = 'R';
        }
    cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
    cout << cnt;
}