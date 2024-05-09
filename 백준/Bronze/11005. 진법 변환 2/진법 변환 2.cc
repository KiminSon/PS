#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n, b;
    vector<int> v;
    cin >> n >> b;
    while (n > 0) {
        v.push_back(n % b);
        n /= b;
    }
    reverse(v.begin(), v.end());
    for (int i: v)
        cout << s[i];
}