#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int l, c;
vector<char> arr;

void f(int depth, int next, string s) {
    if (depth == l) {
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                a++;
            } else {
                b++;
            }
        }
        if (a < 1 || b < 2) {
            return;
        }
        cout << s << '\n';
        return;
    }
    for (int i = next; i < c; i++) {
        f(depth + 1, i + 1, s + arr[i]);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    f(0, 0, "");
}
