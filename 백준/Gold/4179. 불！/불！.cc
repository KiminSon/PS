#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int r, c, jx, jy;
char arr[1000][1000];
int fv[1000][1000], jv[1000][1000];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> r >> c;
    queue<pair<int, int> > q;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            arr[i][j] = s[j];
            fv[i][j] = -1;
            jv[i][j] = -1;
            if (arr[i][j] == 'F') {
                q.push({i, j});
                fv[i][j] = 0;
            }
            if (arr[i][j] == 'J') {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    cout << 1;
                    return 0;
                }
                jx = i;
                jy = j;
                jv[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] != '.' || fv[nx][ny] != -1) {
                continue;
            }
            fv[nx][ny] = fv[x][y] + 1;
            q.push({nx, ny});
        }
    }
    q.push({jx, jy});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] != '.' || jv[nx][ny] != -1) {
                continue;
            }
            if (fv[nx][ny] != -1 && jv[x][y] + 1 >= fv[nx][ny]) {
                continue;
            }
            jv[nx][ny] = jv[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int cnt = 2e9;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) && jv[i][j] != -1) {
                cnt = min(cnt, jv[i][j]);
            }
        }
    }
    if (cnt == 2e9) {
        cout << "IMPOSSIBLE";
    } else {
        cout << cnt + 1;
    }
}
