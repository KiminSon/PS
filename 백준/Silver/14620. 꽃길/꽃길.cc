#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, vsz, ans = 2e9;
int arr[10][10];
int dx[] = {0, 0, 1, -1, 0};
int dy[] = {1, -1, 0, 0, 0};
pair<int, int> s[3];
vector<pair<int, int> > v;

bool death() {
    for (int i = 0; i < 3; i++) {
        auto [x1, y1] = s[i % 3];
        auto [x2, y2] = s[(i + 1) % 3];
        if (abs(x1 - x2) + abs(y1 - y2) <= 2) {
            return 1;
        }
    }
    return 0;
}

void f(int d, int nxt) {
    if (d == 3) {
        int cnt = 0;
        if (death()) {
            return;
        }
        for (auto &[x ,y]: s) {
            for (int i = 0; i < 5; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                cnt += arr[nx][ny];
            }
        }
        ans = min(ans, cnt);
        return;
    }

    for (int i = nxt; i < vsz; i++) {
        auto [x,y] = v[i];
        s[d] = {x, y};
        f(d + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i > 0 && i < n - 1 && j > 0 && j < n - 1) {
                v.push_back({i, j});
            }
        }
    }
    vsz = v.size();
    f(0, 0);
    cout << ans;
}
