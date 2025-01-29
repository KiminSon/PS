#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    while (1) {
        string in;
        getline(cin, in);
        if (in == ".")
            break;
        stack<char> s;
        bool flag = 0;
        for (int i = 0; i < in.size(); i++) {
            char c = in[i];
            if (c == '(' || c == '[')
                s.push(c);
            else if (c == ')') {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else {
                    flag = 1;
                    break;
                }
            } else if (c == ']') {
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0 && s.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}