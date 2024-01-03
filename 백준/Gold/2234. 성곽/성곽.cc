#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Loc {
    int x;
    int y;
};

int n, m;
int castle[50][50];
bool visited[50][50];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int BFS(int startX, int startY) {
    int roomSize = 1;
    queue<Loc> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        int wall = 1;
        for (int i = 0; i < 4; i++) {
            if ((castle[x][y] & wall) != wall) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    roomSize++;
                }
            }
            wall = wall * 2;
        }
    }
    return roomSize;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    int roomCnt = 0;
    int largestRoom1 = -1;
    int largestRoom2 = -1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> castle[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j]) {
                int roomSize = BFS(i, j);
                if (largestRoom1 < roomSize)
                    largestRoom1 = roomSize;
                roomCnt++;
            }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int wall = 1; wall <= 8; wall *= 2)
                if ((castle[i][j] & wall) == wall) {
                    memset(visited, false, sizeof(visited));
                    castle[i][j] -= wall;
                    int roomSize = BFS(i, j);
                    if (largestRoom2 < roomSize)
                        largestRoom2 = roomSize;
                    castle[i][j] += wall;
                }

    cout << roomCnt << "\n" << largestRoom1 << "\n" << largestRoom2;
}