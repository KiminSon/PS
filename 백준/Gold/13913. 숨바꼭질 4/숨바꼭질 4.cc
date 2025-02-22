#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int visited[200001], prv[200001];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, k, cnt;
    cin >> n >> k;
    visited[n] = 1;
    queue<int> q;
    q.push(n);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (cur == k) {
            cnt = visited[k];
            break;
        }
        for (int nxt: {cur + 1, cur - 1, cur * 2}) {
            if (nxt >= 200001 || nxt < 0 || visited[nxt]) {
                continue;
            }
            visited[nxt] = visited[cur] + 1;
            prv[nxt] = cur;
            q.push(nxt);
        }
    }
    vector<int> v;
    for (int i = k; i != n; i = prv[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    cout << cnt - 1 << '\n';
    reverse(v.begin(), v.end());
    for (auto &i: v) {
        cout << i << ' ';
    }
}
