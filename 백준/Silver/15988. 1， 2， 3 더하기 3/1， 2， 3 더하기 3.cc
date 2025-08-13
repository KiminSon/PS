#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll arr[1000001];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        arr[i] = ((arr[i - 1] + arr[i - 2]) % 1000000009 + arr[i - 3]) % 1000000009;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
}
