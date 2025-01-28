#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int arr[100][100] = {0,};
vector<int> v;
int n, m, k, cnt = 0, s = 0;

void dfs(int x, int y) {
    arr[x][y] = 1;
    s++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 1) {
            continue;
        }
        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                arr[y][x] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                s = 0;
                cnt++;
                dfs(i, j);
                v.push_back(s);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for (auto &i: v) {
        cout << i << ' ';
    }
}
