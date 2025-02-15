#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, ans = -2e9;
string s;

int oper(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    }
    if (op == '*') {
        return a * b;
    }
    return a - b;
}

void f(int idx, int val) {
    if (idx == n - 1) {
        ans = max(ans, val);
        return;
    }
    int tmp = oper(val, s[idx + 2] - '0', s[idx + 1]);
    f(idx + 2, tmp);
    if (idx + 4 <= n - 1) {
        tmp = oper(val, oper(s[idx + 2] - '0', s[idx + 4] - '0', s[idx + 3]), s[idx + 1]);
        f(idx + 4, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> s;
    f(0, s[0] - '0');
    cout << ans;
}
