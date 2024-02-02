#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct st {
    int x;
    int y;
};

int r, c;
char board[50][50];
int water[50][50];
int visited[50][50];
queue<st> q, w;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            water[i][j] = -1;
            visited[i][j] = -1;
            if (board[i][j] == 'S') {
                q.push({i, j});
                visited[i][j] = 0;
            }
            if (board[i][j] == '*') {
                w.push({i, j});
                water[i][j] = 0;
            }
        }

    while (!w.empty()) {
        st cur = w.front();
        w.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];
            if (x < 0 || x >= r || y < 0 || y >= c)
                continue;
            if (water[x][y] >= 0 || board[x][y] == 'D' || board[x][y] == 'X')
                continue;
            water[x][y] = water[cur.x][cur.y] + 1;
            w.push({x, y});
        }
    }

    bool flag = 0;
    while (!q.empty() && !flag) {
        st cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];

            if (board[x][y] == 'D') {
                cout << visited[cur.x][cur.y] + 1;
                flag = 1;
                break;
            }

            if (x < 0 || x >= r || y < 0 || y >= c)
                continue;
            if (visited[x][y] >= 0 || board[x][y] == 'X')
                continue;
            if (water[x][y] != -1 && visited[cur.x][cur.y] + 1 >= water[x][y])
                continue;

            visited[x][y] = visited[cur.x][cur.y] + 1;
            q.push({x, y});
        }
    }
    if (!flag)
        cout << "KAKTUS";
}