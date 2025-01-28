#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[100][100];
char c[100][100];
int n, m;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = -1;
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        bool flag = 0;
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 'c') {
                flag = 1;
                cnt = 0;
            }
            if (flag) {
                arr[i][j] = cnt;
                cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}
