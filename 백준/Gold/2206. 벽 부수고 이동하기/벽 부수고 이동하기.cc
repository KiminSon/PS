#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int x, y, d, cst;
};

bool operator <(pt a, pt b) {
    return a.cst > b.cst;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int n, m, k = 1;
    cin >> n >> m;
    int arr[n][m];
    int visited[n][m][k + 1];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
            for (int l = 0; l < k + 1; l++) {
                visited[i][j][l] = 2e9;
            }
        }
    }
    priority_queue<pt> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0] = 0;
    while (q.size()) {
        auto [x,y,d,cst] = q.top();
        if (x == n - 1 && y == m - 1) {
            cout << cst + 1;
            return 0;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (arr[nx][ny] == 1) {
                if (d >= k) {
                    continue;
                }
                if (visited[nx][ny][d + 1] > visited[x][y][d] + 1) {
                    visited[nx][ny][d + 1] = visited[x][y][d] + 1;
                    q.push({nx, ny, d + 1, visited[nx][ny][d + 1]});
                }
            } else if (visited[nx][ny][d] > visited[x][y][d] + 1) {
                visited[nx][ny][d] = visited[x][y][d] + 1;
                q.push({nx, ny, d, visited[nx][ny][d]});
            }
        }
    }
    cout << -1;
}
