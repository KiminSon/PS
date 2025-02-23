#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int a[11];
int o[0];
int mi = 1000000001;
int ma = -1000000001;

void g(int r, int id) {
    if (id == n) {
        if (r > ma)
            ma = r;
        if (r < mi)
            mi = r;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (o[i] > 0) {
            o[i]--;
            if (i == 0)
                g(r + a[id], id + 1);
            else if (i == 1)
                g(r - a[id], id + 1);
            else if (i == 2)
                g(r * a[id], id + 1);
            else
                g(r / a[id], id + 1);
            o[i]++;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 4; i++)
        cin >> o[i];
    g(a[0], 1);
    cout << ma << '\n' << mi;
}