#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        stack<char> st;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            if (s[i] == ')') {
                if (st.size() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                    break;
                }
            }
        }
        if (st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
