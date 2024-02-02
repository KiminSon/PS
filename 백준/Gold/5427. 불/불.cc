#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct st {
    int x;
    int y;
};

int w, h;
int visited[1000][1000];
int fire[1000][1000];
char building[1000][1000];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        bool flag = 0;
        queue<st> q, f;
        cin >> h >> w;
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++) {
                cin >> building[i][j];
                visited[i][j] = -1;
                fire[i][j] = -1;
                if (building[i][j] == '*') {
                    f.push({i, j});
                    fire[i][j] = 0;
                }
                if (building[i][j] == '@') {
                    q.push({i, j});
                    visited[i][j] = 0;
                }
            }

        while (!f.empty()) {
            auto cur = f.front();
            f.pop();
            for (int i = 0; i < 4; i++) {
                int x = cur.x + dx[i];
                int y = cur.y + dy[i];
                if (x < 0 || y < 0 || x >= w || y >= h)
                    continue;
                if (fire[x][y] >= 0 || building[x][y] == '#')
                    continue;

                fire[x][y] = fire[cur.x][cur.y] + 1;
                f.push({x, y});
            }
        }
        while (!q.empty() && !flag) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = cur.x + dx[i];
                int y = cur.y + dy[i];
                if (x < 0 || y < 0 || x >= w || y >= h) {
                    cout << visited[cur.x][cur.y] + 1 << '\n';
                    flag = 1;
                    break;
                }
                if (visited[x][y] >= 0 || building[x][y] == '#')
                    continue;
                if (fire[x][y] != -1 && visited[cur.x][cur.y] + 1 >= fire[x][y])
                    continue;
                visited[x][y] = visited[cur.x][cur.y] + 1;
                q.push({x, y});
            }
        }
        if (!flag)
            cout << "IMPOSSIBLE\n";
    }
}