#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int c[3], s[3], e[3];
    for (int i = 0; i < 3; i++) {
        cin >> c[i];
    }
    int sum = 0, min = 101, max = 0;
    for (int i = 0; i < 3; i++) {
        cin >> s[i] >> e[i];
        if (s[i] < min) {
            min = s[i];
        }
        if (e[i] > max) {
            max = e[i];
        }
    }
    for (int i = min; i < max; i++) {
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            if (s[j] <= i && i < e[j]) {
                cnt++;
            }
        }
        sum += c[cnt - 1] * cnt;
    }
    cout << sum;
}
