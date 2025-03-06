#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Seg {
    vector<int> seg, arr;
    int leafSize, l, r;

    Seg(int initSize) {
        leafSize = initSize;
        int h = ceil(log2(initSize));
        int sz = 2 << h;
        seg.resize(sz, 2e9);
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
        seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
    }

    int segQuery(int left, int right) {
        l = left;
        r = right;
        return query(1, 0, leafSize - 1);
    }

    int query(int n, int s, int e) {
        if (l > e || r < s) {
            return 2e9;
        }
        if (l <= s && e <= r) {
            return seg[n];
        }
        int mid = (s + e) / 2;
        int lval = query(n * 2, s, mid);
        int rval = query(n * 2 + 1, mid + 1, e);
        return min(lval, rval);
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
        cin >> i;
    }
    seg.init(1, 0, n - 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << seg.segQuery(a - 1, b - 1) << '\n';
    }
}
