#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void cmp(string s1, string s2) {
    string tmp;
    cin >> tmp;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != tmp[i]) {
            cout << "NE\n";
            return;
        }
    }

    for (int i = s2.size() - 1, j = tmp.size() - 1; i >= 0; i--, j--) {
        if (s2[i] != tmp[j] || s1.size() > j) {
            cout << "NE\n";
            return;
        }
    }

    cout << "DA\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    string s;
    cin >> n >> s;
    string s1 = "", s2 = "";
    int i = 0;
    for (; i < s.size(); i++) {
        if (s[i] == '*') {
            i++;
            break;
        }
        s1 += s[i];
    }
    for (; i < s.size(); i++) {
        s2 += s[i];
    }
    while (n--) {
        cmp(s1, s2);
    }
}
