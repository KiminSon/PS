#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[20];
int n, s, cnt = 0;

void f(int depth, int next, int sum) {
    if (sum == s) {
        cnt++;
    }
    if (depth == n) {
        return;
    }
    for (int i = next; i < n; i++) {
        f(depth + 1, i + 1, sum + arr[i]);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    f(0, 0, 0);
    if (s == 0) {
        cnt--;
    }
    cout << cnt;
}
