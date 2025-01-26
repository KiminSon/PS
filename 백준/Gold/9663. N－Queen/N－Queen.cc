#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, cnt = 0;
int b[16] = {0,};

bool p(int x) {
    for (int i = 0; i < x; i++) {
        if (b[x] == b[i] || x - i == abs(b[x] - b[i])) {
            return 0;
        }
    }
    return 1;
}

void f(int x) {
    if (x == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        b[x] = i;
        if (p(x)) {
            f(x + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    f(0);
    cout << cnt;
}
