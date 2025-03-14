#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int i = 0, v = 0;
};

struct Seg {
    int sz, idx, val;
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
        int a;
        cin >> a;
        if (a == 2) {
            cout << seg.seg[1].i + 1 << '\n';
        } else {
            int b, c;
            cin >> b >> c;
            seg.segUpdate(b - 1, c);
        }
    }
}
