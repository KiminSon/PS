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
        vector<int> v;
        int x = 0, y = 0;
        while (1) {
            if (x == n / 2 && y == n / 2) {
                dq.push_back(v);
                break;
            }
            v.push_back(arr[x][y]);
            x += 1;
            y += 1;
        }
        v.clear();

        x = 0, y = n / 2;
        while (1) {
            if (x == n / 2 && y == n / 2) {
                dq.push_back(v);
                break;
            }
            v.push_back(arr[x][y]);
            x += 1;
        }
        v.clear();

        x = 0, y = n - 1;
        while (1) {
            if (x == n / 2 && y == n / 2) {
                dq.push_back(v);
                break;
            }
            v.push_back(arr[x][y]);
            x += 1;
            y += -1;
        }
        v.clear();

        x = n / 2, y = n - 1;
        while (1) {
            if (x == n / 2 && y == n / 2) {
                dq.push_back(v);
                break;
            }
            v.push_back(arr[x][y]);
            y += -1;
        }
        v.clear();

        x = n - 1, y = n - 1;
        while (1) {
            if (x == n / 2 && y == n / 2) {
                dq.push_back(v);
                break;
            }
            v.push_back(arr[x][y]);
            x += -1;
            y += -1;
        }
        v.clear();

        x = n - 1, y = n / 2;
        while (1) {
            if (x == n / 2 && y == n / 2) {
                dq.push_back(v);
                break;
            }
            v.push_back(arr[x][y]);
            x += -1;
        }
        v.clear();

        x = n - 1, y = 0;
        while (1) {
            if (x == n / 2 && y == n / 2) {
                dq.push_back(v);
                break;
            }
            v.push_back(arr[x][y]);
            x += -1;
            y += 1;
        }
        v.clear();

        x = n / 2, y = 0;
        while (1) {
            if (x == n / 2 && y == n / 2) {
                dq.push_back(v);
                break;
            }
            v.push_back(arr[x][y]);
            y += 1;
        }

        for (int i = 0; i < d; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }

        v = dq.front();
        dq.pop_front();
        x = 0, y = 0;
        for (int i = 0; i < n / 2; i++) {
            arr[x][y] = v[i];
            x += 1;
            y += 1;
        }

        v = dq.front();
        dq.pop_front();
        x = 0, y = n / 2;
        for (int i = 0; i < n / 2; i++) {
            arr[x][y] = v[i];
            x += 1;
        }

        v = dq.front();
        dq.pop_front();
        x = 0, y = n - 1;
        for (int i = 0; i < n / 2; i++) {
            arr[x][y] = v[i];
            x += 1;
            y += -1;
        }

        v = dq.front();
        dq.pop_front();
        x = n / 2, y = n - 1;
        for (int i = 0; i < n / 2; i++) {
            arr[x][y] = v[i];
            y += -1;
        }

        v = dq.front();
        dq.pop_front();
        x = n - 1, y = n - 1;
        for (int i = 0; i < n / 2; i++) {
            arr[x][y] = v[i];
            x += -1;
            y += -1;
        }

        v = dq.front();
        dq.pop_front();
        x = n - 1, y = n / 2;
        for (int i = 0; i < n / 2; i++) {
            arr[x][y] = v[i];
            x += -1;
        }

        v = dq.front();
        dq.pop_front();
        x = n - 1, y = 0;
        for (int i = 0; i < n / 2; i++) {
            arr[x][y] = v[i];
            x += -1;
            y += 1;
        }

        v = dq.front();
        dq.pop_front();
        x = n / 2, y = 0;
        for (int i = 0; i < n / 2; i++) {
            arr[x][y] = v[i];
            y += 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
