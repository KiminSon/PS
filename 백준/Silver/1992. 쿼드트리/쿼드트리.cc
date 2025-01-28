#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[64][64];

void f(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[x][y] != arr[i][j]) {
                cout << "(";
                f(x, y, n / 2);
                f(x, y + n / 2, n / 2);
                f(x + n / 2, y, n / 2);
                f(x + n / 2, y + n / 2, n / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << arr[x][y];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    f(0, 0, n);
}
