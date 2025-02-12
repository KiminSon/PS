#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[50][50];
int visited[50][50];
int n, l, r, cnt;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void re() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        bool flag = 0;
        re();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    int pcnt = 0;
                    int s = 0;
                    queue<pair<int, int> > que, q;
                    que.push({i, j});
                    visited[i][j] = 1;
                    pcnt++;
                    s += arr[i][j];
                    q.push({i, j});
                    while (!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
                                continue;
                            }
                            int tmp = abs(arr[cur.first][cur.second] - arr[nx][ny]);
                            if (!(l <= tmp && tmp <= r)) {
                                continue;
                            }
                            q.push({nx, ny});
                            que.push({nx, ny});
                            s += arr[nx][ny];
                            pcnt++;
                            visited[nx][ny] = 1;
                        }
                    }
                    if (que.size() > 1) {
                        flag = 1;
                    }
                    while (!que.empty()) {
                        auto cur = que.front();
                        que.pop();
                        arr[cur.first][cur.second] = s / pcnt;
                    }
                }
            }
        }
        if (!flag) {
            break;
        }
        cnt++;
    }
    cout << cnt;
}
