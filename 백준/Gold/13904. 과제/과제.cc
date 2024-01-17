#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, d, w, ans = 0;
bool visited[1000];
vector<pair<ll, ll>> v;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n;
    v.assign(n, {0, 0});
    for (auto &i: v) {
        cin >> d >> w;
        i = {d, w};
    }
    sort(v.begin(), v.end(), greater<>());
    d = v[0].first;
    w = d;

    for (ll i = 0; i < w; i++) {
        ll idx, max = 0;
        for (ll j = 0; j < n; j++) {
            if (!visited[j] && v[j].first >= d) {
                if (v[j].second > max) {
                    max = v[j].second;
                    idx = j;
                } else if (v[j].second == max) {
                    if (v[j].first >= v[idx].first) {
                        idx = j;
                    }
                }
            }
        }
        if (max != 0) {
            ans += max;
            visited[idx] = true;
        }
        d--;
    }
    cout << ans;
}