#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int visited[1000][1000], arr[1000][1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
// 0 = R, 1 = L, 2 = D, 3 = U

struct pt {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'R') {
                arr[i][j] = 0;
            } else if (c == 'L') {
                arr[i][j] = 1;
            } else if (c == 'D') {
                arr[i][j] = 2;
            } else {
                arr[i][j] = 3;
            }
        }
    }
    int cnt = 0, area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                area++;
                cnt++;
                queue<pt> q;
                q.push({i, j});
                visited[i][j] = area;
                while (q.size()) {
                    auto [x,y] = q.front();
                    q.pop();
                    int cur = arr[x][y];
                    int nx = x + dx[cur];
                    int ny = y + dy[cur];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = area;
                        q.push({nx, ny});
                    } else if (visited[nx][ny] != area) {
                        cnt--;
                    }
                }
            }
        }
    }
    cout << cnt;
}
