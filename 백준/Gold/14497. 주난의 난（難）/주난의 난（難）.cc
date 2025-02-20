#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int n, m, sx, sy;
    cin >> n >> m;
    int arr[n][m];
    int visited[n][m];
    string s;
    for (int i = 0; i < 4; i++) {
        cin >> sx;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') {
                sx = i;
                sy = j;
                arr[i][j] = 3;
            } else if (s[j] == '#') {
                arr[i][j] = 2;
            } else {
                arr[i][j] = s[j] - '0';
            }
        }
    }
    int cnt = 0;
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = 0;
                if (arr[i][j] == -1) {
                    arr[i][j] = 0;
                }
            }
        }

        queue<pair<int, int> > q;
        q.push({sx, sy});
        visited[sx][sy] = 1;
        while (q.size()) {
            auto [x,y] = q.front();
            if (arr[x][y] == 2) {
                cout << cnt + 1;
                return 0;
            }
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                    continue;
                }
                if (arr[nx][ny] == 2) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
                if (arr[nx][ny] == 1) {
                    visited[nx][ny] = 1;
                    arr[nx][ny] = -1;
                }
                if (arr[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        cnt++;
    }
}
