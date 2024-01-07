#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string arr[51];
string white_arr[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string black_arr[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int white_first(int x, int y) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[x + i][y + j] != white_arr[i][j])
                result++;
        }
    }
    return result;
}

int black_first(int x, int y) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[x + i][y + j] != black_arr[i][j])
                result++;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, result = 64;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int t_white, t_black;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            t_white = white_first(i, j);
            t_black = black_first(i, j);
            result = min(result, min(t_black, t_white));
        }
    }
    cout << result << '\n';
}
