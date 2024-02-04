#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int visited[1000001];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == g) {
            cout << visited[cur] - 1;
            return 0;
        }
        if (cur + u <= f && visited[cur + u] == 0) {
            q.push(cur + u);
            visited[cur + u] = visited[cur] + 1;
        }
        if (cur - d > 0 && visited[cur - d] == 0) {
            q.push(cur - d);
            visited[cur - d] = visited[cur] + 1;
        }
    }
    cout << "use the stairs";
}