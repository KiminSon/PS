#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s[3];
    int k = 3;
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
        if (s[i] != "FizzBuzz" && s[i] != "Fizz" && s[i] != "Buzz") {
            k += stoi(s[i]);
            break;
        }
        k--;
    }
    if (k % 3 == 0 && k % 5 == 0) {
        cout << "FizzBuzz";
    } else if (k % 3 == 0) {
        cout << "Fizz";
    } else if (k % 5 == 0) {
        cout << "Buzz";
    } else {
        cout << k;
    }
}
