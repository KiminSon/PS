#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, ans = 2e9;
int arr[10][10];
int num[10], visited[10];

void f(int d) {
    if (d == n) {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[num[i]][num[i + 1]] == 0) {
                return;
            }
            cnt += arr[num[i]][num[i + 1]];
        }
        if (arr[num[n - 1]][num[0]] == 0) {
            return;
        }
        cnt += arr[num[n - 1]][num[0]];
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            num[d] = i;
            f(d + 1);
            visited[i] = 0;
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    f(0);
    cout << ans;
}
