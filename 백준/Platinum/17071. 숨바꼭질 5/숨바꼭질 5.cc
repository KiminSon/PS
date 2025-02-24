#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int visited[500001][2];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, k, t = 1;
    cin >> n >> k;
    if (n == k) {
        cout << 0;
        return 0;
    }
    queue<int> q;
    q.push(n);
    visited[n][0] = 1;
    while (q.size()) {
        k += t;
        if (k > 500000) {
            cout << -1;
            return 0;
        }
        if (visited[k][t % 2]) {
            cout << t;
            return 0;
        }
        int qsz = q.size();
        for (int i = 0; i < qsz; i++) {
            int x = q.front();
            q.pop();
            for (int nx: {x + 1, x - 1, x * 2}) {
                if (nx < 0 || nx > 500000 || visited[nx][t % 2]) {
                    continue;
                }
                visited[nx][t % 2] = visited[x][(t + 1) % 2] + 1;
                if (nx == k) {
                    cout << t;
                    return 0;
                }
                q.push(nx);
            }
        }
        t++;
    }
}
