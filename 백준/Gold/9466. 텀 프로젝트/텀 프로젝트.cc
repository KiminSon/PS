#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, s[100000], cnt;
bool visited[100000], finished[100000];

void dfs(int curr) {
    visited[curr] = 1;
    int next = s[curr];
    if (visited[next]) {
        if (!finished[next]) {
            for (int i = next; i != curr; i = s[i])
                cnt++;
            cnt++;
        }
    } else
        dfs(next);
    finished[curr] = 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            s[i]--;
            visited[i] = 0;
            finished[i] = 0;
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i);
        cout << n - cnt << '\n';
    }
}