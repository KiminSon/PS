#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt {
    ll mn, mx;
};

struct Seg {
    vector<pt> seg, arr;
    ll leafSize, l, r;

    Seg(int initSize) {
        leafSize = initSize;
        int h = ceil(log2(initSize));
        int sz = 2 << h;
        arr.resize(initSize);
        seg.resize(sz, {(ll) 9e18, (ll) -9e18});
    }

    void init(int n, int s, int e) {
        if (s == e) {
            seg[n] = arr[s];
            return;
        }
        int mid = (s + e) / 2;
        init(n * 2, s, mid);
        init(n * 2 + 1, mid + 1, e);
        seg[n].mn = min(seg[n * 2].mn, seg[n * 2 + 1].mn);
        seg[n].mx = max(seg[n * 2].mx, seg[n * 2 + 1].mx);
    }

    pt segQuery(int left, int right) {
        l = left;
        r = right;

        return query(1, 0, leafSize - 1);
    }

    pt query(int n, int s, int e) {
        if (l > e || r < s) {
            return {(ll) 9e18, (ll) -9e18};
        }
        if (l <= s && e <= r) {
            return seg[n];
        }
        int mid = (s + e) / 2;
        auto lval = query(n * 2, s, mid);
        auto rval = query(n * 2 + 1, mid + 1, e);
        ll mn = min(lval.mn, rval.mn);
        ll mx = max(lval.mx, rval.mx);
        return {mn, mx};
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    Seg seg(n);
    for (auto &i: seg.arr) {
        ll tmp;
        cin >> tmp;
        i = {tmp, tmp};
    }
    seg.init(1, 0, n - 1);
    while (m--) {
        ll a, b;
        cin >> a >> b;
        auto [mn, mx] = seg.segQuery(a - 1, b - 1);
        cout << mn << ' ' << mx << '\n';
    }
}
