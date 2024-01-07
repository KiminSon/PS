#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char arr[50][50];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        int tmp = 1;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                tmp++;
                ans = max(tmp, ans);
            } else {
                tmp = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int tmp = 1;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == arr[j + 1][i]) {
                tmp++;
                ans = max(tmp, ans);
            } else {
                tmp = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++) {
            if (arr[i][j] != arr[i][j + 1]) {
                swap(arr[i][j], arr[i][j + 1]);
                int tmp = 1;
                for (int k = 0; k < n - 1; k++) {
                    if (arr[i][k] == arr[i][k + 1]) {
                        tmp++;
                        ans = max(tmp, ans);
                    } else {
                        tmp = 1;
                    }
                }

                tmp = 1;
                for (int k = 0; k < n - 1; k++) {
                    if (arr[k][j] == arr[k + 1][j]) {
                        tmp++;
                        ans = max(tmp, ans);
                    } else {
                        tmp = 1;
                    }
                }

                tmp = 1;
                for (int k = 0; k < n - 1; k++) {
                    if (arr[k][j + 1] == arr[k + 1][j + 1]) {
                        tmp++;
                        ans = max(tmp, ans);
                    } else {
                        tmp = 1;
                    }
                }
                swap(arr[i][j], arr[i][j + 1]);
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++) {
            if (arr[j][i] != arr[j + 1][i]) {
                swap(arr[j][i], arr[j + 1][i]);
                int tmp = 1;
                for (int k = 0; k < n - 1; k++) {
                    if (arr[k][i] == arr[k + 1][i]) {
                        tmp++;
                        ans = max(tmp, ans);
                    } else {
                        tmp = 1;
                    }
                }

                tmp = 1;
                for (int k = 0; k < n - 1; k++) {
                    if (arr[j][k] == arr[j][k + 1]) {
                        tmp++;
                        ans = max(tmp, ans);
                    } else {
                        tmp = 1;
                    }
                }

                tmp = 1;
                for (int k = 0; k < n - 1; k++) {
                    if (arr[j + 1][k] == arr[j + 1][k + 1]) {
                        tmp++;
                        ans = max(tmp, ans);
                    } else {
                        tmp = 1;
                    }
                }
                swap(arr[j][i], arr[j + 1][i]);
            }
        }
    cout << ans;
}