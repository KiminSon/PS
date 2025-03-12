#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int x, y;
};

int n, m, sz, ans = 2e9;
int arr[50][50], tmp[50][50];
int vir[10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<pt> v;

void f(int d, int nxt) {
    if (d == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = arr[i][j];
                if (tmp[i][j] == 2) {
                    tmp[i][j] = 0;
                }
            }
        }
        int cnt = 0;
        queue<pt> q;
        for (int i = 0; i < d; i++) {
            q.push(v[vir[i]]);
            auto [x,y] = v[vir[i]];
            tmp[x][y] = 1;
        }
        while (q.size()) {
            auto [x,y] = q.front();
            cnt = max(tmp[x][y], cnt);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || tmp[nx][ny]) {
                    continue;
                }
                tmp[nx][ny] = tmp[x][y] + 1;
                q.push({nx, ny});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tmp[i][j] == 0) {
                    return;
                }
            }
        }
        ans = min(cnt - 1, ans);
        return;
    }
    for (int i = nxt; i < sz; i++) {
        vir[d] = i;
        f(d + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                v.push_back({i, j});
            }
        }
    }
    sz = v.size();
    f(0, 0);
    if (ans == 2e9) {
        ans = -1;
    }
    cout << ans;
}
