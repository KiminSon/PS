#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
bool dp[101];
string s;
vector<string> v;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < s.size(); i++)
        if (dp[i] || i == 0) {
            for (int j = 0; j < n; j++) {
                if (i + v[j].size() > s.size())
                    continue;
                bool flag = true;
                for (int k = 0; k < v[j].size(); k++)
                    if (v[j][k] != s[i + k]) {
                        flag = false;
                        break;
                    }
                if (flag)
                    dp[i + v[j].size()] = true;
            }
        }

    cout << dp[s.size()];
}