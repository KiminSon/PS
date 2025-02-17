#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int visited[200][200][31];
int arr[200][200];
int k, w, h;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int hx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int hy[] = {2, -2, 2, -2, 1, -1, 1, -1};

struct pt {
    int x, y, depth, cst;
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
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
            for (int l = 0; l < k + 1; l++) {
                visited[i][j][l] = 2e9;
            }
        }
    }
    priority_queue<pt> q;
    visited[0][0][0] = 0;
    q.push({0, 0, 0, arr[0][0]});
    while (q.size()) {
        auto [x, y, depth, cst] = q.top();
        if (x == h - 1 && y == w - 1) {
            cout << cst;
            return 0;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || arr[nx][ny] == 1) {
                continue;
            }
            if (visited[nx][ny][depth] > visited[x][y][depth] + 1) {
                visited[nx][ny][depth] = visited[x][y][depth] + 1;
                q.push({nx, ny, depth, visited[nx][ny][depth]});
            }
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + hx[i];
            int ny = y + hy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || depth >= k || arr[nx][ny] == 1) {
                continue;
            }
            if (visited[nx][ny][depth + 1] > visited[x][y][depth] + 1) {
                visited[nx][ny][depth + 1] = visited[x][y][depth] + 1;
                q.push({nx, ny, depth + 1, visited[nx][ny][depth + 1]});
            }
        }
    }
    cout << -1;
}
