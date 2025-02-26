#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int s, e, w;
};

bool operator<(pt a, pt b) {
    return a.w > b.w;
}

vector<int> arr, sz;

int f(int x) {
    if (x == arr[x]) {
        return arr[x];
    }
    return arr[x] = f(arr[x]);
}

bool un(int a, int b) {
    a = f(a);
    b = f(b);
    if (a == b) {
        return 0;
    }
    if (sz[a] < sz[b]) {
        sz[b] += sz[a];
        arr[a] = b;
    } else {
        sz[a] += sz[b];
        arr[b] = a;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int v, e;
    cin >> v >> e;
    priority_queue<pt> pq;
    arr.resize(v + 1);
    sz.resize(v + 1);
    for (int i = 0; i < e; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        pq.push({s, e, w});
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= v; i++) {
        arr[i] = i;
        sz[i] = 1;
    }
    while (cnt < v - 1) {
        auto [s,e,w] = pq.top();
        pq.pop();
        if (un(s, e)) {
            cnt++;
            ans += w;
        }
    }
    cout << ans;
}
