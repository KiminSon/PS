#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, tx, ty;
int arr[101][101];
int visited[101];
queue<int> q;

void bfs(int k) {
    q.push(k);

    while (!q.empty()) {
        k = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
            if (arr[k][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = visited[k] + 1;
            }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> tx >> ty >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    bfs(tx);

    if (visited[ty] == 0)
        visited[ty] = -1;

    cout << visited[ty];
}