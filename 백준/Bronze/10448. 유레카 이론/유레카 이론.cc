#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[50];

void tri(int n) {
    for (int i: arr)
        for (int j: arr)
            for (int k: arr)
                if (i + j + k == n) {
                    cout << 1 << '\n';
                    return;
                }
    cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    for (int i = 0; i < 50; i++)
        arr[i] = (i + 1) * (i + 2) / 2;

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        tri(n);
    }
}