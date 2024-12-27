#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dx2[] = {-1, -1, 1, 1};
int dy2[] = {1, -1, 1, -1};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int k;
                cin >> k;
                v[i][j] = k;
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt1 = v[i][j], cnt2 = v[i][j];
                for (int k = 0; k < 4; k++) {
                    int x = i, y = j;
                    int x2 = i, y2 = j;
                    for (int l = 0; l < m - 1; l++) {
                        x += dx[k];
                        y += dy[k];
                        x2 += dx2[k];
                        y2 += dy2[k];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            cnt1 += v[x][y];
                        }
                        if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n) {
                            cnt2 += v[x2][y2];
                        }
                    }
                }
                ans = max(ans, max(cnt1, cnt2));
            }
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }
}
