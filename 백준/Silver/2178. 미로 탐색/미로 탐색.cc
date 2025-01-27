#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int check[100][100];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string s[100];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    queue<pair<int, int>> q;
    q.push({0, 0});
    check[0][0] = 1;
    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (s[nx][ny] == '0' || check[nx][ny] >= 1)
                continue;
            check[nx][ny] = check[c.first][c.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << check[n - 1][m - 1];
}