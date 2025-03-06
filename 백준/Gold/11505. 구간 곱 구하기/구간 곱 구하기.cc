#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Seg {
    vector<ll> seg, arr;
    ll leafSize, l, r, idx, val;

    Seg(int initSize) {
        leafSize = initSize;
        int h = ceil(log2(initSize));
        int sz = 2 << h;
        seg.resize(sz, 1);
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
        seg[n] = seg[n * 2] * seg[n * 2 + 1] % 1000000007;
    }

    ll segQuery(int left, int right) {
        l = left - 1;
        r = right - 1;
        return query(1, 0, leafSize - 1);
    }

    ll query(int n, int s, int e) {
        if (l > e || r < s) {
            return 1;
        }
        if (l <= s && e <= r) {
            return seg[n];
        }
        int mid = (s + e) / 2;
        ll lsum = query(n * 2, s, mid);
        ll rsum = query(n * 2 + 1, mid + 1, e);
        return lsum * rsum % 1000000007;
    }

    void segUpdate(int index, ll value) {
        idx = index - 1;
        val = value;
        update(1, 0, leafSize - 1);
    }

    void update(int n, int s, int e) {
        if (idx < s || idx > e) {
            return;
        }
        if (s == e) {
            seg[n] = val;
            arr[idx] = val;
            return;
        }
        int mid = (s + e) / 2;
        update(n * 2, s, mid);
        update(n * 2 + 1, mid + 1, e);
        seg[n] = seg[n * 2] * seg[n * 2 + 1] % 1000000007;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    m += k;
    Seg seg(n);
    for (auto &i: seg.arr) {
        cin >> i;
    }
    seg.init(1, 0, n - 1);
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            seg.segUpdate(b, c);
        } else {
            cout << seg.segQuery(b, c) << '\n';
        }
    }
}
