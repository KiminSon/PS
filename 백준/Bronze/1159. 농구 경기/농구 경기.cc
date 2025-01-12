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
    int cnt[26] = {0,};
    cin >> n;
    if (n < 5) {
        cout << "PREDAJA";
        return 0;
    }

    while (n--) {
        string s;
        cin >> s;
        cnt[s[0] - 'a']++;
    }

    string s = "";
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 4) {
            s += (char) (i + 'a');
        }
    }
    
    if (!s.empty()) {
        cout << s;
    } else {
        cout << "PREDAJA";
    }
}
