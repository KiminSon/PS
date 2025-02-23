#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, mn = 2e9, mx = -2e9;
int arr[11];

void f(int depth, int ans, int add, int dif, int mux, int div) {
    if (depth == n) {
        mn = min(mn, ans);
        mx = max(mx, ans);
        return;
    }
    if (add > 0) {
        f(depth + 1, ans + arr[depth], add - 1, dif, mux, div);
    }
    if (dif > 0) {
        f(depth + 1, ans - arr[depth], add, dif - 1, mux, div);
    }
    if (mux > 0) {
        f(depth + 1, ans * arr[depth], add, dif, mux - 1, div);
    }
    if (div > 0) {
        f(depth + 1, ans / arr[depth], add, dif, mux, div - 1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int tmp[4];
    for (int i = 0; i < 4; i++) {
        cin >> tmp[i];
    }
    f(1, arr[0], tmp[0], tmp[1], tmp[2], tmp[3]);
    cout << mx << '\n' << mn;
}
