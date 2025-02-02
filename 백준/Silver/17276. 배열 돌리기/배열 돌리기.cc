#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        int arr[n][n];
        if (d < 0) {
            d += 360;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        if (d == 0 || d == 360) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << arr[i][j] << ' ';
                }
                cout << '\n';
            }
            continue;
        }
        d /= 45;

        deque<vector<int> > dq;
        vector<vector<int> > v(8, vector<int>(n / 2));
        int x = 0, y = n - 1, h = n / 2;
        for (int i = 0; i < h; i++) {
            v[0][i] = arr[x][x];
            v[1][i] = arr[x][h];
            v[2][i] = arr[x][y];
            v[3][i] = arr[h][y];
            v[4][i] = arr[y][y];
            v[5][i] = arr[y][h];
            v[6][i] = arr[y][x];
            v[7][i] = arr[h][x];
            x += 1;
            y += -1;
        }

        for (int i = 0; i < 8 - d; i++) {
            dq.push_back(v[i]);
        }
        for (int i = 7; i >= 8 - d; i--) {
            dq.push_front(v[i]);
        }

        for (int i = 0; i < 8; i++) {
            v[i] = dq.front();
            dq.pop_front();
        }

        x = 0, y = n - 1;
        for (int i = 0; i < n / 2; i++) {
            arr[x][x] = v[0][i];
            arr[x][h] = v[1][i];
            arr[x][y] = v[2][i];
            arr[h][y] = v[3][i];
            arr[y][y] = v[4][i];
            arr[y][h] = v[5][i];
            arr[y][x] = v[6][i];
            arr[h][x] = v[7][i];
            x += 1;
            y += -1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
