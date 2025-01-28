#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmp(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    vector<string> v;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        string tmp;
        for (int i = 0; i < s.length(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                if (tmp.size() == 1 && tmp[0] == '0') {
                    tmp = s[i];
                } else {
                    tmp += s[i];
                }
            } else {
                if (tmp.size()) {
                    v.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        if (tmp.size()) {
            v.push_back(tmp);
            tmp.clear();
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto &i: v) {
        cout << i << '\n';
    }
}
