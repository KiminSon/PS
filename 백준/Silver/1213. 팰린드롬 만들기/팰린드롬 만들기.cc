#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> v(26);
    string s;
    char c = 'a';
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        v[s[i] - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 == 1) {
            odd++;
            c = (char) (i + 'A');
            v[i]--;
        }
    }
    if (odd > 1) {
        cout << "I'm Sorry Hansoo";
    } else {
        s.clear();
        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) {
                for (int j = 0; j < v[i] / 2; j++) {
                    s += (char) (i + 'A');
                }
            }
        }
        cout << s;
        if (c != 'a') {
            cout << c;
        }
        reverse(s.begin(), s.end());
        cout << s;
    }
}
