#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    while (1) {
        vector<int> v;
        int n, s = 0;
        cin >> n;
        if (n == -1)
            break;
        for (int i = 1; i * i < n; i++)
            if (n % i == 0) {
                v.push_back(i);
                if (i != 1)
                    v.push_back(n / i);
                s += i + n / i;
            }
        if (2 * n == s) {
            sort(v.begin(), v.end());
            cout << n << " = ";
            for (int i = 0; i < v.size() - 1; i++)
                cout << v[i] << " + ";
            cout << v[v.size() - 1] << '\n';
        } else
            cout << n << " is NOT perfect.\n";
    }
}