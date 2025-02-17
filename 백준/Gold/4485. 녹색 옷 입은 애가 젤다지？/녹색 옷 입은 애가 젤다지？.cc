#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int x, y, cst;
    bool operator>(const pt &other) const {
        return cst > other.cst;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<vector<int>> arr(n, vector<int>(n));
        vector<vector<int>> visited(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        priority_queue<pt, vector<pt>, greater<>> q;
        visited[0][0] = arr[0][0];
        q.push({0, 0, arr[0][0]});

        while (!q.empty()) {
            auto [x, y, cst] = q.top();
            q.pop();
            
            if (visited[x][y] < cst) continue; // 불필요한 중복 방문 방지

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                int new_cost = cst + arr[nx][ny];
                if (visited[nx][ny] > new_cost) {
                    visited[nx][ny] = new_cost;
                    q.push({nx, ny, new_cost});
                }
            }
        }

        cout << "Problem " << t << ": " << visited[n - 1][n - 1] << '\n';
        t++;
    }
}
