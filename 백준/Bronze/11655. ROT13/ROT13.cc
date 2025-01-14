#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s1 = "abcdefghijklmnopqrstuvwxyz";
    string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z')
            s[i] = s1[(s[i] - 'a' + 13) % 26];
        else if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = s2[(s[i] - 'A' + 13) % 26];
    }
    cout << s;
}
