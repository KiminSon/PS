#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Seg {
    int idx, val, l, r, sz;
    vector<int> seg, arr;

    Seg(int n) {
        sz = n;
        arr.resize(n);
        seg.resize(2 << (int) ceil(log2(n)));
    }

    void init(int n, int s, int e) {
        if (s == e) {
            seg[n] = arr[s];
            return;
        }
        int m = (s + e) / 2;
        init(n * 2, s, m);
        init(n * 2 + 1, m + 1, e);
        seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
    }

    void segUpdate(int index, int value) {
        idx = index;
        val = value;
        update(1, 0, sz - 1);
    }

    void update(int n, int s, int e) {
        if (idx < s || idx > e) {
            return;
        }
        if (s == e) {
            seg[n] = val;
            arr[s] = val;
            return;
        }
        int m = (s + e) / 2;
        update(n * 2, s, m);
        update(n * 2 + 1, m + 1, e);
        seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
    }

    int segQuery(int left, int right) {
        l = left;
        r = right;
        return query(1, 0, sz - 1);
    }

    int query(int n, int s, int e) {
        if (l > e || r < s) {
            return 2e9;
        }
        if (l <= s && e <= r) {
            return seg[n];
        }
        int m = (s + e) / 2;
        int lv = query(n * 2, s, m);
        int rv = query(n * 2 + 1, m + 1, e);
        return min(lv, rv);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n;
    Seg seg(n);
    for (auto &i: seg.arr) {
        cin >> i;
    }
    seg.init(1, 0, n - 1);
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            seg.segUpdate(b - 1, c);
        } else {
            cout << seg.segQuery(b - 1, c - 1) << '\n';
        }
    }
}
