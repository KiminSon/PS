#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int m[3] = {0, 0, 0};
vector<vector<int> > v;

void f(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (v[x][y] != v[i][j]) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        f(x + k * n / 3, y + l * n / 3, n / 3);
                    }
                }
                return;
            }
        }
    }
    m[v[x][y] + 1]++;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    v = vector<vector<int> >(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    f(0, 0, n);

    for (int i = 0; i < 3; i++) {
        cout << m[i] << '\n';
    }
}
