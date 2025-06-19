#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct st {
    int p, f, s, v, c;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, mp, mf, ms, mv, ans = -1, cst = 1e9;
    cin >> n >> mp >> mf >> ms >> mv;
    vector<st> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;
    }

    vector<int> best_comb;

    for (int i = 1; i < (1 << n); i++) {
        int p = 0, f = 0, s = 0, v = 0, c = 0;
        vector<int> comb;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                p += arr[j].p;
                f += arr[j].f;
                s += arr[j].s;
                v += arr[j].v;
                c += arr[j].c;
                comb.push_back(j + 1);
            }
        }
        if (p >= mp && f >= mf && s >= ms && v >= mv) {
            if (c < cst) {
                cst = c;
                best_comb = comb;
            } else if (c == cst && comb < best_comb) {
                best_comb = comb;
            }
        }
    }

    if (best_comb.empty()) {
        cout << -1;
        return 0;
    }

    cout << cst << '\n';
    for (int i : best_comb) {
        cout << i << ' ';
    }

    return 0;
}
