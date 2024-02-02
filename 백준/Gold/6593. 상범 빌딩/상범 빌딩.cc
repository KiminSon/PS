#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct st {
    int x;
    int y;
    int z;
    int t;
};

int l, r, c;
char building[30][30][30];
bool visited[30][30][30];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    while (1) {
        bool flag = 0;
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;
        queue<st> q;
        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++)
                for (int k = 0; k < c; k++) {
                    visited[i][j][k] = 0;
                    cin >> building[i][j][k];
                    if (building[i][j][k] == 'S')
                        q.push({i, j, k, 0});
                }
        while (!q.empty()) {
            st cur = q.front();
            q.pop();
            for (int i = 0; i < 6; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nz = cur.z + dz[i];
                if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c)
                    continue;
                if (building[nx][ny][nz] == 'E') {
                    cout << "Escaped in " << cur.t + 1 << " minute(s).\n";
                    flag = 1;
                    break;
                }
                if (building[nx][ny][nz] == '.' && visited[nx][ny][nz] == 0) {
                    q.push({nx, ny, nz, cur.t + 1});
                    visited[nx][ny][nz] = 1;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << "Trapped!\n";
    }
}