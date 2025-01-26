#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[26][2] = {-2,};

void pre(int node) {
    if (node < 0) {
        return;
    }
    cout << (char) (node + 'A');
    pre(arr[node][0]);
    pre(arr[node][1]);
}

void in(int node) {
    if (node < 0) {
        return;
    }
    in(arr[node][0]);
    cout << (char) (node + 'A');
    in(arr[node][1]);
}

void po(int node) {
    if (node < 0) {
        return;
    }
    po(arr[node][0]);
    po(arr[node][1]);
    cout << (char) (node + 'A');
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        if (c2 == '.') {
            arr[c1 - 'A'][0] = -1;
        } else {
            arr[c1 - 'A'][0] = c2 - 'A';
        }
        if (c3 == '.') {
            arr[c1 - 'A'][1] = -1;
        } else {
            arr[c1 - 'A'][1] = c3 - 'A';
        }
    }
    pre(0);
    cout << '\n';
    in(0);
    cout << '\n';
    po(0);
}
