#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int x, y, mod;
};

struct dr {
    int x, y;
};

int n, m, ans = 2e9, cnt;
vector<vector<int> > arr(8, vector<int>(8)), tmp;
pt cctv[8];
int cmod[8];
int idx;
vector<vector<vector<pair<int, int> > > > v = {
    {
        {{0, 1}},
        {{1, 0}},
        {{0, -1}},
        {{-1, 0}}
    },
    {
        {{0, 1}, {0, -1}},
        {{1, 0}, {-1, 0}}
    },
    {
        {{0, 1}, {1, 0}},
        {{1, 0}, {0, -1}},
        {{0, -1}, {-1, 0}},
        {{-1, 0}, {0, 1}}
    },
    {
        {{0, -1}, {1, 0}, {-1, 0}},
        {{0, 1}, {1, 0}, {-1, 0}},
        {{0, 1}, {0, -1}, {-1, 0}},
        {{0, 1}, {0, -1}, {1, 0}}
    },
    {
        {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
    }
};


void f(int d) {
    if (d == idx) {
        tmp = arr;
        int tcnt = cnt;
        for (int i = 0; i < idx; i++) {
            auto [x,y,mod] = cctv[i];
            for (int j = 0; j < v[mod][cmod[i]].size(); j++) {
                int nx = x;
                int ny = y;
                while (1) {
                    nx += v[mod][cmod[i]][j].first;
                    ny += v[mod][cmod[i]][j].second;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || tmp[nx][ny] == 6) {
                        break;
                    }
                    if (!tmp[nx][ny]) {
                        tcnt--;
                    }
                    tmp[nx][ny] = -1;
                }
            }
        }
        ans = min(tcnt, ans);
        return;
    }
    for (int i = 0; i < v[cctv[d].mod].size(); i++) {
        cmod[d] = i;
        f(d + 1);
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
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] && arr[i][j] != 6) {
                pt p;
                p.x = i;
                p.y = j;
                p.mod = arr[i][j] - 1;
                cctv[idx] = p;
                idx++;
            } else if (!arr[i][j]) {
                cnt++;
            }
        }
    }
    f(0);
    cout << ans;
}
