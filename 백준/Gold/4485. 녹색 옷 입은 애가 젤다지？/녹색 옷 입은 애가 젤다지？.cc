#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int x, y, cst;
};

bool operator <(pt a, pt b) {
    return a.cst > b.cst;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int arr[125][125];
int visited[125][125];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t = 1;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                visited[i][j] = 2e9;
            }
        }
        priority_queue<pt> q;
        q.push({0, 0, arr[0][0]});
        visited[0][0] = arr[0][0];
        while (q.size()) {
            auto cur = q.top();
            q.pop();
            int x = cur.x;
            int y = cur.y;;
            int cst = cur.cst;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                int ncst = cst + arr[nx][ny];
                if (visited[nx][ny] > ncst) {
                    visited[nx][ny] = ncst;
                    q.push({nx, ny, ncst});
                }
            }
        }

        cout << "Problem " << t << ": " << visited[n - 1][n - 1] << '\n';
        t++;
    }
}
