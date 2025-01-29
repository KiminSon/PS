#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[8][8];
int visited[8][8];
int n, m, ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<pair<int, int> > vList, wList;

void re() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
}

void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || arr[nx][ny]) {
            continue;
        }
        dfs(nx, ny);
    }
}

int s() {
    re();
    for (pair<int, int> p: vList) {
        dfs(p.first, p.second);;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0 && !visited[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
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
            if (arr[i][j] == 2) {
                vList.push_back({i, j});
            }
            if (arr[i][j] == 0) {
                wList.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < wList.size() - 2; i++) {
        for (int j = i + 1; j < wList.size() - 1; j++) {
            for (int k = j + 1; k < wList.size(); k++) {
                arr[wList[i].first][wList[i].second] = 1;
                arr[wList[j].first][wList[j].second] = 1;
                arr[wList[k].first][wList[k].second] = 1;
                ans = max(ans, s());
                arr[wList[i].first][wList[i].second] = 0;
                arr[wList[j].first][wList[j].second] = 0;
                arr[wList[k].first][wList[k].second] = 0;
            }
        }
    }
    cout << ans;
}
