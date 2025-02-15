#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    cin >> m >> n;
    int arr[n][m];
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny]) {
                continue;
            }
            arr[nx][ny] = arr[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
            cnt = max(cnt, arr[i][j]);
        }
    }
    cout << cnt - 1;
}
