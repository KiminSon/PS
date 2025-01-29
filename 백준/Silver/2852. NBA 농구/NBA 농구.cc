#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void p(int t) {
    if (t / 60 < 10) {
        cout << 0;
    }
    cout << t / 60 << ":";
    if (t % 60 < 10) {
        cout << 0;
    }
    cout << t % 60;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, v1t = 0, v2t = 0;
    cin >> n;
    vector<int> v1(48 * 60), v2(48 * 60);
    while (n--) {
        int tmp;
        string s;
        cin >> tmp >> s;
        string s1 = s.substr(0, 2), s2 = s.substr(3, 2);
        int t = stoi(s1) * 60 + stoi(s2);
        if (tmp == 1) {
            for (int i = t; i < 48 * 60; i++) {
                v1[i]++;
            }
        } else {
            for (int i = t; i < 48 * 60; i++) {
                v2[i]++;
            }
        }
    }
    for (int i = 0; i < 48 * 60; i++) {
        if (v1[i] > v2[i]) {
            v1t++;
        }
        if (v2[i] > v1[i]) {
            v2t++;
        }
    }
    p(v1t);
    cout << '\n';
    p(v2t);
}
