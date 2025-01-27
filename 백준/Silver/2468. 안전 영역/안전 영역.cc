#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int minW = 101, maxW = -1, ans = 1, n;
int arr[100][100];
int visited[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void re() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
}

void dfs(int x, int y, int d) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] <= d || visited[nx][ny] == 1) {
            continue;
        }
        dfs(nx, ny, d);
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
            minW = min(minW, arr[i][j]);
            maxW = max(maxW, arr[i][j]);
        }
    }
    for (int i = minW - 1; i <= maxW + 1; i++) {
        re();
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (arr[j][k] > i && visited[j][k] == 0) {
                    dfs(j, k, i);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
