#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s1, s2;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    if (s1 == s2)
        cout << 1;
    else
        cout << 0;
}