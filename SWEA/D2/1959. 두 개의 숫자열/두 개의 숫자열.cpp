#include<iostream>

using namespace std;

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int ans = 0;

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++) {
            int j;
            cin >> j;
            a[i] = j;
        }

        for (int i = 0; i < m; i++) {
            int j;
            cin >> j;
            b[i] = j;
        }
        if (m > n) {
            for (int i = 0; i < m - n + 1; i++) {
                int result = 0;
                for (int j = 0; j < n; j++) {
                    result += b[i + j] * a[j];
                }
                if (result > ans) {
                    ans = result;
                }
            }
        } else {
            for (int i = 0; i < n - m + 1; i++) {
                int result = 0;
                for (int j = 0; j < m; j++) {
                    result += a[i + j] * b[j];
                }
                if (result > ans) {
                    ans = result;
                }
            }
        }
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}
