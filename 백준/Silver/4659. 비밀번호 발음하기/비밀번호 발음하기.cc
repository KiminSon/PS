#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    while (1) {
        string s;
        cin >> s;
        if (s == "end") {
            return 0;
        }
        cout << "<";
        bool b1 = 0, b2 = 1, b3 = 1;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                b1 = 1;
            }
        }
        if (s.size() >= 3) {
            for (int i = 0; i < s.size() - 2; i++) {
                if (isVowel(s[i])) {
                    if (isVowel(s[i + 1])) {
                        if (isVowel(s[i + 2])) {
                            b2 = 0;
                        }
                    }
                } else {
                    if (!isVowel(s[i + 1])) {
                        if (!isVowel(s[i + 2])) {
                            b2 = 0;
                        }
                    }
                }
            }
        }
        if (s.size() >= 2) {
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] != 'e' && s[i] != 'o' && s[i] == s[i + 1]) {
                    b3 = 0;
                }
            }
        }
        if (b1 && b2 && b3) {
            cout << s << "> is acceptable.\n";
        } else {
            cout << s << "> is not acceptable.\n";
        }
    }
}
