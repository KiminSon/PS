#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, ans = 0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (st.top() == s[i]) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        if (st.empty()) {
            ans++;
        }
    }
    cout << ans;
}
