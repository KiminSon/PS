#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void f(string s, set<int> st, vector<int> v) {
    if (s.empty()) {
        vector<int> tmp = v;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size() - 1; i++) {
            if (tmp[i] + 1 != tmp[i + 1]) {
                return;
            }
        }
        for (auto i: v) {
            cout << i << ' ';
        }
        exit(0);
    }
    int nm;
    nm = stoi(s.substr(0, 1));
    if (nm != 0 && st.find(nm) == st.end()) {
        set<int> tmp = st;
        vector<int> temp = v;
        tmp.insert(nm);
        temp.push_back(nm);
        f(s.substr(1, s.size()), tmp, temp);
    }
    if (s.size() > 1) {
        nm = stoi(s.substr(0, 2));
        if (st.find(nm) == st.end() && nm < 51) {
            set<int> tmp = st;
            vector<int> temp = v;
            tmp.insert(nm);
            temp.push_back(nm);
            f(s.substr(2, s.size()), tmp, temp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    f(s, set<int>(), vector<int>());
}
