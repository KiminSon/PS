#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int i = 2e9, v = 2e9;
};

struct Seg {
    int sz, idx, val, l, r;
    vector<pt> seg, arr;

    Seg(int n) {
        sz = n;
        int h = ceil(log2(n));
        int ss = 2 << h;
        arr.resize(n);
        seg.resize(ss);
    }

    void init(int n, int s, int e) {
        if (s == e) {
            seg[n] = arr[s];
            return;
        }
        int m = (s + e) / 2;
        init(n * 2, s, m);
        init(n * 2 + 1, m + 1, e);
        pt p;
        if (seg[n * 2].v < seg[n * 2 + 1].v) {
            p.v = seg[n * 2].v;
            p.i = seg[n * 2].i;
        } else if (seg[n * 2].v > seg[n * 2 + 1].v) {
            p.v = seg[n * 2 + 1].v;
            p.i = seg[n * 2 + 1].i;
        } else {
            if (seg[n * 2].i < seg[n * 2 + 1].i) {
                p.v = seg[n * 2].v;
                p.i = seg[n * 2].i;
            } else if (seg[n * 2].i > seg[n * 2 + 1].i) {
                p.v = seg[n * 2 + 1].v;
                p.i = seg[n * 2 + 1].i;
            }
        }
        seg[n] = p;
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
            arr[s].v = val;
            seg[n].v = val;
            return;
        }
        int m = (s + e) / 2;
        update(n * 2, s, m);
        update(n * 2 + 1, m + 1, e);
        pt p;
        if (seg[n * 2].v < seg[n * 2 + 1].v) {
            p.v = seg[n * 2].v;
            p.i = seg[n * 2].i;
        } else if (seg[n * 2].v > seg[n * 2 + 1].v) {
            p.v = seg[n * 2 + 1].v;
            p.i = seg[n * 2 + 1].i;
        } else {
            if (seg[n * 2].i < seg[n * 2 + 1].i) {
                p.v = seg[n * 2].v;
                p.i = seg[n * 2].i;
            } else if (seg[n * 2].i > seg[n * 2 + 1].i) {
                p.v = seg[n * 2 + 1].v;
                p.i = seg[n * 2 + 1].i;
            }
        }
        seg[n] = p;
    }

    pt segQuery(int left, int right) {
        l = left;
        r = right;
        return query(1, 0, sz - 1);
    }

    pt query(int n, int s, int e) {
        pt p;
        if (l > e || r < s) {
            return p;
        }
        if (l <= s && e <= r) {
            return seg[n];
        }
        int m = (s + e) / 2;
        pt lv = query(n * 2, s, m);
        pt rv = query(n * 2 + 1, m + 1, e);

        if (lv.v < rv.v) {
            p.v = lv.v;
            p.i = lv.i;
        } else if (lv.v > rv.v) {
            p.v = rv.v;
            p.i = rv.i;
        } else {
            if (lv.i < rv.i) {
                p.v = lv.v;
                p.i = lv.i;
            } else if (lv.i > rv.i) {
                p.v = rv.v;
                p.i = rv.i;
            }
        }

        return p;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    Seg seg(n);
    for (int i = 0; i < n; i++) {
        pt p;
        cin >> p.v;
        p.i = i;
        seg.arr[i] = p;
    }
    seg.init(1, 0, n - 1);
    int m;
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 2) {
            pt p = seg.segQuery(b - 1, c - 1);
            cout << p.i + 1 << '\n';
        } else {
            seg.segUpdate(b - 1, c);
        }
    }
}
