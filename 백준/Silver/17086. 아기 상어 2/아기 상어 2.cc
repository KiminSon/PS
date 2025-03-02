#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, cnt;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
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

    while (q.size()) {
        auto [x,y] = q.front();
        q.pop();
        cnt = max(cnt, arr[x][y]);
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny]) {
                continue;
            }
            arr[nx][ny] = arr[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << cnt - 1;
}
