#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    while (1) {
        getline(cin, s);
        if (s == ".") {
            return 0;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            }
            if (s[i] == ']') {
                if (st.size() && st.top() == '[') {
                    st.pop();
                } else {
                    st.push(s[i]);
                    break;
                }
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
        if (st.size()) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }
}
