#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, m, h, cnt = 4, cn, vsz;
int arr[32][32];
vector<pair<int, int> > v;

bool isCan() {
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int j = 1; j <= h; j++) {
            if (arr[cur][j] == 1) {
                cur++;
            } else if (arr[cur - 1][j] == 1) {
                cur--;
            }
        }
        if (cur != i) {
            return 0;
        }
    }
    return 1;
}

void f(int d, int nxt) {
    if (d >= cnt || d > 3) {
        return;
    }
    if (isCan()) {
        cnt = min(d, cnt);
        return;
    }

    for (int i = nxt; i < vsz; i++) {
        auto [x, y] = v[i];
        if (!arr[x][y]) {
            bool a = 1, b = 1;
            arr[x][y] = 1;
            if (arr[x - 1][y] == -1) {
                a = 0;
            }
            arr[x - 1][y] = -1;
            if (arr[x + 1][y] == -1) {
                b = 0;
            }
            arr[x + 1][y] = -1;
            f(d + 1, i + 1);
            arr[x][y] = 0;
            if (a) {
                arr[x - 1][y] = 0;
            }
            if (b) {
                arr[x + 1][y] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[b][a] = 1;
        arr[b - 1][a] = -1;
        arr[b + 1][a] = -1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= h; j++) {
            if (!arr[i][j]) {
                v.push_back({i, j});
            }
        }
    }
    vsz = v.size();

    if (isCan()) {
        cout << 0;
        return 0;
    }

    f(0, 0);

    if (cnt == 4) {
        cnt = -1;
    }
    cout << cnt;
}
