#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, cnt;
int arr[100101];
int visited[100101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    arr[1001] = 1;
    visited[1001] = 1;
    cnt++;
    queue<int> q;
    q.push(1001);

    vector<vector<int> > v(100101);
    for (int i = 0; i < m; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        v[sx * 1000 + sy].push_back(ex * 1000 + ey);
    }

    while (q.size()) {
        auto cur = q.front();
        q.pop();
        if (!arr[cur]) {
            continue;
        }
        for (auto &i: v[cur]) {
            if (visited[i] && !arr[i]) {
                q.push(i);
            }
            if (arr[i] == 0) {
                cnt++;
            }
            arr[i] = 1;
        }
        int x = cur / 1000;
        int y = cur % 1000;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nxt = nx * 1000 + ny;
            if (nx < 1 || nx > n || ny < 1 || ny > n || visited[nxt]) {
                continue;
            }
            q.push(nxt);
            visited[nxt] = 1;
        }
    }
    cout << cnt;
}
