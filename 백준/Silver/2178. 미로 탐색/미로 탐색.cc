#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
int arr[101][101] = {0,};
int visited[101][101] = {0,};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct loc {
    int x = 0;
    int y = 0;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    queue<loc> q;
    loc l;
    l.x = 1;
    l.y = 1;
    visited[l.x][l.y] = 1;
    q.push(l);
    while (!q.empty()) {
        loc cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (visited[nx][ny] || arr[nx][ny] == 0) {
                continue;
            }
            visited[nx][ny] = visited[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
    cout << visited[n][m];
}
