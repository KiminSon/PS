#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, mn = 2e9;
int arr[50][50];
vector<pair<int, int> > cv, hv;

int s() {
    int cnt = 0;
    for (int i = 0; i < hv.size(); i++) {
        int tmp = 2e9;
        for (int j = 0; j < cv.size(); j++) {
            auto idx = cv[j];
            int cx = idx.first;
            int cy = idx.second;
            if (arr[cx][cy] == 3) {
                auto indx = hv[i];
                int hx = indx.first;
                int hy = indx.second;
                tmp = min(tmp, abs(cx - hx) + abs(cy - hy));
            }
        }
        cnt += tmp;
    }
    return cnt;
}

void f(int depth, int nxt) {
    if (depth == m) {
        mn = min(mn, s());
        return;
    }
    for (int i = nxt; i < cv.size(); i++) {
        auto idx = cv[i];
        arr[idx.first][idx.second] = 3;
        f(depth + 1, i + 1);
        arr[idx.first][idx.second] = 2;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                cv.push_back({i, j});
            }
            if (arr[i][j] == 1) {
                hv.push_back({i, j});
            }
        }
    }
    f(0, 0);
    cout << mn;
}
