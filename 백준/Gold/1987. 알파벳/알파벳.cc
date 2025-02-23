#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char arr[20][20];
bool visited[26];
int n, m, ans = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt) {
    cnt++;
    ans = max(cnt, ans);
    visited[arr[x][y] - 'A'] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[arr[nx][ny] - 'A']) {
            continue;
        }
        dfs(nx, ny, cnt);
    }
    visited[arr[x][y] - 'A'] = 0;
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
    dfs(0, 0, 0);
    cout << ans;
}
