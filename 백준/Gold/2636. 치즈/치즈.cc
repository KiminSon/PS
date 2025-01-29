#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[100][100];
int visited[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;

int c() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
            if (arr[i][j] == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || arr[nx][ny] == -1) {
            continue;
        }
        if (arr[nx][ny] == 1) {
            arr[nx][ny] = -1;
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
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int cnt = 0, ans = 0;
    while (1) {
        int tmp = c();
        if (tmp == 0) {
            break;
        }
        cnt++;
        ans = tmp;
        dfs(0, 0);
    }
    cout << cnt << '\n' << ans;
}
