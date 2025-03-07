#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    int l = 0, r = 0;
};

bool operator <(pt a, pt b) {
    return a.r < b.r;
}

struct Seg {
    vector<pt> seg, arr;
    int leafSize, r, l, idx, val;

    Seg(int initSize) {
        leafSize = initSize;
        int h = ceil(log2(initSize));
        int sz = 2 << h;
        seg.resize(sz);
        arr.resize(initSize);
    }

    void init(int n, int s, int e) {
        if (s == e) {
            seg[n] = arr[s];
            return;
        }
        int mid = (s + e) / 2;
        init(n * 2, s, mid);
        init(n * 2 + 1, mid + 1, e);
        pt lpt = seg[n * 2];
        pt rpt = seg[n * 2 + 1];
        int arr[4];
        arr[0] = lpt.l;
        arr[1] = lpt.r;
        arr[2] = rpt.l;
        arr[3] = rpt.r;
        sort(arr, arr + 4, greater<int>());
        seg[n].r = arr[0];
        seg[n].l = arr[1];
    }

    void segUpdate(int index, int value) {
        idx = index;
        val = value;
        update(1, 0, leafSize - 1);
    }

    void update(int n, int s, int e) {
        if (idx < s || idx > e) {
            return;
        }
        if (s == e) {
            seg[n].r = val;
            arr[idx].r = val;
            return;
        }
        int mid = (s + e) / 2;
        update(n * 2, s, mid);
        update(n * 2 + 1, mid + 1, e);
        pt lpt = seg[n * 2];
        pt rpt = seg[n * 2 + 1];
        int arr[4];
        arr[0] = lpt.l;
        arr[1] = lpt.r;
        arr[2] = rpt.l;
        arr[3] = rpt.r;
        sort(arr, arr + 4, greater<int>());
        seg[n].r = arr[0];
        seg[n].l = arr[1];
    }

    pt segQuery(int left, int right) {
        l = left;
        r = right;
        return query(1, 0, leafSize - 1);
    }

    pt query(int n, int s, int e) {
        pt tmp;
        if (l > e || r < s) {
            return tmp;
        }
        if (l <= s && e <= r) {
            return seg[n];
        }
        int mid = (s + e) / 2;
        pt lpt = query(n * 2, s, mid);
        pt rpt = query(n * 2 + 1, mid + 1, e);
        int arr[4];
        arr[0] = lpt.l;
        arr[1] = lpt.r;
        arr[2] = rpt.l;
        arr[3] = rpt.r;
        sort(arr, arr + 4, greater<int>());
        tmp.r = arr[0];
        tmp.l = arr[1];
        return tmp;
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
    for (auto &i: seg.arr) {
        cin >> i.r;
    }
    seg.init(1, 0, n - 1);
    int m;
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            seg.segUpdate(b - 1, c);
        } else {
            pt tmp = seg.segQuery(b - 1, c - 1);
            cout << tmp.r + tmp.l << '\n';
        }
    }
}
