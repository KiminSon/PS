#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int arr[26] = {0,};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }
}
