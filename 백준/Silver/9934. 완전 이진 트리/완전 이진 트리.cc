#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int idx, depth, sz;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int k, n;
    cin >> k;
    n = (1 << k);
    int arr[n];
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
    }
    queue<pt> q;
    q.push({n / 2, 1, n / 4});
    int prev = 1;
    while (q.size()) {
        auto [idx, depth, sz] = q.front();
        q.pop();
        if (prev < depth) {
            cout << '\n';
            prev++;
        }
        if (k == depth) {
            cout << arr[idx] << ' ';
            continue;
        }
        cout << arr[idx] << ' ';
        q.push({idx - sz, depth + 1, sz / 2});
        q.push({idx + sz, depth + 1, sz / 2});
    }
}
