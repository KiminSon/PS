#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int c[15];
int n, t = 0;

bool a(int l) {
    for (int i = 0; i < l; i++)
        if (c[i] == c[l] || abs(c[l] - c[i]) == l - i)
            return 0;
    return 1;
}

void q(int x) {
    if (x == n)
        t++;
    else
        for (int i = 0; i < n; i++) {
            c[x] = i;
            if (a(x))
                q(x + 1);
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    q(0);
    cout << t;
}