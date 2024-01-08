#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool arr[1001];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, l, ans;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> ans;
        arr[ans] = true;
    }
    ans = 0;

    for (int i = 1; i < 1001; i++)
        if (arr[i]) {
            ans++;
            for (int j = i; j < i + l; j++) {
                if (j == 1001)
                    break;
                arr[j] = false;
            }
        }

    cout << ans;
}