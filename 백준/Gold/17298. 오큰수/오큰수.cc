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
    int arr[n];
    stack<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        arr[i] = -1;
        int t;
        cin >> t;
        while (1) {
            if (st.empty() || st.top().second >= t) {
                st.push({i, t});
                break;
            }
            arr[st.top().first] = t;
            st.pop();
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}
