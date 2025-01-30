#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, r;
int arr[300][300];

/*
 * 1. n또는 m이 2가 되기 전까지 넣음
 * 2. 횟수만큼 옮기는 로직 필요
 * 3. R을 줄이기 위해 길이를 R에다가 mod연산
 */

void f(int x, int y, int xl, int yl) {
    deque<int> dq;
    for (int i = x; i < x + xl - 1; i++) {
        dq.push_back(arr[i][y]);
    }
    for (int i = y; i < y + yl - 1; i++) {
        dq.push_back(arr[x + xl - 1][i]);
    }
    for (int i = x + xl - 1; i > x; i--) {
        dq.push_back(arr[i][y + yl - 1]);
    }
    for (int i = y + yl - 1; i > y; i--) {
        dq.push_back(arr[x][i]);
    }

    int R = r % ((xl + yl) * 2 - 4);

    for (int i = 0; i < R; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
    }

    for (int i = x; i < x + xl - 1; i++) {
        arr[i][y] = dq.front();
        dq.pop_front();
    }
    for (int i = y; i < y + yl - 1; i++) {
        arr[x + xl - 1][i] = dq.front();
        dq.pop_front();
    }
    for (int i = x + xl - 1; i > x; i--) {
        arr[i][y + yl - 1] = dq.front();
        dq.pop_front();
    }
    for (int i = y + yl - 1; i > y; i--) {
        arr[x][i] = dq.front();
        dq.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int nn = n, mm = m;
    int sx = 0, sy = 0;
    f(sx, sy, nn, mm);
    while (1) {
        if (nn == 2 || mm == 2) {
            break;
        }
        nn -= 2;
        mm -= 2;
        sx += 1;
        sy += 1;
        f(sx, sy, nn, mm);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
