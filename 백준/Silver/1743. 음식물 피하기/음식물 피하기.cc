#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, k;
int field[101][101];
bool visited[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<int> v;
int area = 1;

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (ny < 0 || nx < 0 || nx > n || ny > m)
            continue;

        if (field[nx][ny] == 1 && visited[nx][ny] == 0) {
            area++;
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    while (k--) {
        int r, c;
        cin >> r >> c;
        field[r][c] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (field[i][j] == 1 && visited[i][j] == 0) {
                dfs(i, j);
                v.push_back(area);
                area = 1;
            }

    sort(v.begin(), v.end(), greater<>());
    cout << v[0];
}