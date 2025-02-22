#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, mn = 9e18, mx = -9e18;
string mxstr, mnstr;
char arr[9];
bool visited[10];

void dfs(int d, string s) {
    if (d == n + 1) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == '<') {
                if (s[i] > s[i + 1]) {
                    return;
                }
            } else {
                if (s[i] < s[i + 1]) {
                    return;
                }
            }
        }
        ll tmp = stoll(s);
        if (mn > tmp) {
            mn = tmp;
            mnstr = s;
        }
        if (mx < tmp) {
            mx = tmp;
            mxstr = s;
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            string tmp = s;
            tmp += i + '0';
            dfs(d + 1, tmp);
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
        cin >> arr[i];
    }
    dfs(0, "");

    for (int i = 0; i < n + 1; i++) {
        cout << mxstr[i];
    }
    cout << '\n';
    for (int i = 0; i < n + 1; i++) {
        cout << mnstr[i];
    }
}
