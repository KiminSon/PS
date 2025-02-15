#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int d[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {1, 3, 9},
    {3, 1, 9},
    {3, 9, 1},
    {1, 9, 3}
};

int n, arr[3], visited[60][60][60];

struct loc {
    int a, b, c;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    queue<loc> q;
    visited[arr[0]][arr[1]][arr[2]] = 1;
    q.push({arr[0], arr[1], arr[2]});
    while (q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (visited[0][0][0]) {
            cout << visited[0][0][0] - 1;
            return 0;
        }
        for (int i = 0; i < 6; i++) {
            int na = max(0, a - d[i][0]);
            int nb = max(0, b - d[i][1]);
            int nc = max(0, c - d[i][2]);
            if (visited[na][nb][nc]) {
                continue;
            }
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
}
