#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, cnt = 0;
int visited[100001];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (cur == k) {
            cnt++;
        } else {
            if (cur * 2 <= 100000 && (!visited[cur * 2] || visited[cur] + 1 <= visited[cur * 2])) {
                q.push(cur * 2);
                visited[cur * 2] = visited[cur] + 1;
            }
            if (cur + 1 <= 100000 && (!visited[cur + 1] || visited[cur] + 1 <= visited[cur + 1])) {
                q.push(cur + 1);
                visited[cur + 1] = visited[cur] + 1;
            }
            if (0 <= cur - 1 && (!visited[cur - 1] || visited[cur] + 1 <= visited[cur - 1])) {
                q.push(cur - 1);
                visited[cur - 1] = visited[cur] + 1;
            }
        }
    }
    cout << visited[k] - 1 << '\n' << cnt;
}
