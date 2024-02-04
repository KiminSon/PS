#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool visited[100000];
int n, t, g;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> t >> g;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int cur = q.front();
            q.pop();
            if (cur == g) {
                cout << cnt;
                return 0;
            }
            if (cur + 1 < 100000)
                if (!visited[cur + 1]) {
                    visited[cur + 1] = 1;
                    q.push(cur + 1);
                }
            if (cur * 2 < 100000) {
                int t = 0;
                if (cur * 2 != 0) {
                    string s = to_string(cur * 2);
                    s[0]--;
                    t = stoi(s);
                }
                if (!visited[t]) {
                    visited[t] = 1;
                    q.push(t);
                }
            }
        }
        cnt++;
        if (cnt > t)
            break;
    }
    cout << "ANG";
}