#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[100][3];
int strike[100];
int ball[100];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t, n, ans = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> strike[i] >> ball[i];
        for (int j = 0; j < 3; j++) {
            arr[i][j] = n % 10;
            n /= 10;
        }
    }

    for (int i = 123; i < 988; i++) {
        bool flag = true;
        int fi = i % 10;
        int se = (i / 10) % 10;
        int th = i / 100;

        if (fi != se && se != th && th != fi && fi != 0 && se != 0 && th != 0) {
            for (int j = 0; j < t; j++) {
                int s = 0, b = 0;
                for (int k = 0; k < 3; k++)
                    if (arr[j][k] == fi || arr[j][k] == se || arr[j][k] == th)
                        b++;
                if (arr[j][0] == fi) {
                    s++;
                    b--;
                }
                if (arr[j][1] == se) {
                    s++;
                    b--;
                }
                if (arr[j][2] == th) {
                    s++;
                    b--;
                }
                if (strike[j] != s || ball[j] != b)
                    flag = false;
            }
            if (flag)
                ans++;
        }
    }
    cout << ans;
}