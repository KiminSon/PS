#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sum;
vector<pair<ll, pair<ll, ll>>> segtree(4097153);

void findsum(ll idx, ll start, ll end) {
    // 완전 포함되면 sum추가 후 종료
    if (segtree[idx].second.first >= start && segtree[idx].second.second <= end) {
        sum += segtree[idx].first;
        return;
    }
    // idx의 끝이 처음보다 작거나, 처음이 끝보다 크면 리턴
    if (segtree[idx].second.first > end || segtree[idx].second.second < start)
        return;

    // 재귀
    findsum(idx * 2, start, end);
    findsum(idx * 2 + 1, start, end);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n, m, treesize;
    cin >> n >> m >> treesize;
    m += treesize;

    // 트리 사이즈
    treesize = pow(2, ceil(log2(n)) + 1); // 16
    ll idx = treesize / 2; // 8
    ll realidx = 1;

    // 트리 구성 8부터 5 + 8 = 13까지
    for (ll i = 0; i < n; i++) { // 있는 노드 입력
        cin >> segtree[idx].first;
        segtree[idx].second.first = realidx;
        segtree[idx].second.second = realidx;
        idx++;
        realidx++;
    }
    for (ll i = 0; i < treesize - n; i++) { // 나머지 노드는 0처리
        segtree[idx].first = 0;
        segtree[idx].second.first = realidx;
        segtree[idx].second.second = realidx;
        idx++;
        realidx++;
    }
    for (ll i = treesize / 2 - 1; i > 0; i--) { // 부모노드 업데이트
        segtree[i].first = segtree[2 * i].first + segtree[2 * i + 1].first;
        segtree[i].second.first = min(segtree[2 * i].second.first, segtree[2 * i + 1].second.first);
        segtree[i].second.second = max(segtree[2 * i].second.second, segtree[2 * i + 1].second.second);
    }

    // m+k만큼 반복문 돌림
    ll a, b, c;
    while (m--) {
        cin >> a >> b >> c;

        // 업데이트
        if (a == 1) {
            b += treesize / 2 - 1;
            segtree[b].first = c;
            b /= 2;
            while (b > 0) {
                segtree[b].first = segtree[2 * b].first + segtree[2 * b + 1].first;
                b /= 2;
            }
        } // 출력
        else {
            sum = 0;
            findsum(1, b, c);
            cout << sum << '\n';
        }
    }
}