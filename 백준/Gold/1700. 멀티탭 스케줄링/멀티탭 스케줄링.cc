#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int order[101], use[101];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> order[i];

    if (n >= k) {
        cout << 0;
        return 0;
    }
    int o_idx = 0, c_idx = 0;

    while (c_idx < n) {
        if (find(use, use + n, order[o_idx]) == use + n) {
            use[c_idx] = order[o_idx];
            c_idx++;
        }
        o_idx++;
    }

    for (int i = n; i < k; i++) {
        int cur = order[i];

        if (find(use, use + n, cur) == use + n) {
            pair<int, int> m = {INT_MIN, INT_MIN};

            for (int j = 0; j < n; j++) {
                pair<int, int> c;
                int pos = find(order + i, order + k, use[j]) - order;

                if (pos == k)
                    c = {INT_MAX, j};
                else
                    c = {pos, j};

                if (c.first > m.first)
                    m = c;
            }
            use[m.second] = cur;
            ans++;
        }
    }
    cout << ans;
}