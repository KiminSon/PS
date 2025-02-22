#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int x, y, cst;
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
    int r, c, sx, sy;
    cin >> r >> c;
    char arr[r][c];
    int ice[r][c];
    bool visited[r][c];
    bool ic[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ic[i][j] = 0;
            visited[i][j] = 0;
            ice[i][j] = 2e9;
            cin >> arr[i][j];
            if (arr[i][j] == 'L') {
                sx = i;
                sy = j;
            }
        }
    }
    priority_queue<pt> pq;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j] && arr[i][j] != 'X') {
                visited[i][j] = 1;
                ice[i][j] = 0;
                queue<pair<int, int> > q;
                q.push({i, j});
                while (q.size()) {
                    auto [x,y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) {
                            continue;
                        }
                        if (arr[nx][ny] == 'X') {
                            ice[nx][ny] = 1;
                            visited[nx][ny] = 1;
                            pq.push({nx, ny, 1});
                        } else {
                            visited[nx][ny] = 1;
                            ice[nx][ny] = 0;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    while (pq.size()) {
        auto [x,y,cst] = pq.top();
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] != 'X') {
                continue;
            }
            if (ice[nx][ny] > ice[x][y] + 1) {
                ice[nx][ny] = ice[x][y] + 1;
                pq.push({nx, ny, ice[nx][ny]});
            }
        }
    }

    int ans = 0;
    pq.push({sx, sy, 0});
    ic[sx][sy] = 1;
    while (pq.size()) {
        auto [x,y,cst] = pq.top();
        ans = max(ice[x][y], ans);
        if (!(x == sx && y == sy) && arr[x][y] == 'L') {
            cout << ans;
            return 0;
        }
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || ic[nx][ny]) {
                continue;
            }
            ic[nx][ny] = 1;
            pq.push({nx, ny, ice[nx][ny]});
        }
    }
}
