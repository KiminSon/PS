import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Pt implements Comparable<Pt> {
        int x, y, d, cst;

        public Pt(int x, int y, int d, int cst) {
            this.x = x;
            this.y = y;
            this.d = d;
            this.cst = cst;
        }

        @Override
        public int compareTo(Pt o) {
            return Integer.compare(this.cst, o.cst);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n, m, k;
        int[][][] visited;
        int[][] arr;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = 1;
        visited = new int[k + 1][n][m];
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j) - '0';
                for (int l = 0; l <= k; l++) {
                    visited[l][i][j] = Integer.MAX_VALUE - 1000;
                }
            }
        }

        PriorityQueue<Pt> q = new PriorityQueue<>();
        q.add(new Pt(0, 0, 0, 0));
        visited[0][0][0] = 0;
        while (!q.isEmpty()) {
            Pt cur = q.poll();
            if (cur.x == n - 1 && cur.y == m - 1) {
                System.out.print(cur.cst + 1);
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (arr[nx][ny] == 1) {
                    if (cur.d >= k) {
                        continue;
                    }
                    if (visited[cur.d + 1][nx][ny] > visited[cur.d][cur.x][cur.y] + 1) {
                        visited[cur.d + 1][nx][ny] = visited[cur.d][cur.x][cur.y] + 1;
                        q.add(new Pt(nx, ny, cur.d + 1, visited[cur.d + 1][nx][ny]));
                    }
                } else if (visited[cur.d][nx][ny] > visited[cur.d][cur.x][cur.y] + 1) {
                    visited[cur.d][nx][ny] = visited[cur.d][cur.x][cur.y] + 1;
                    q.add(new Pt(nx, ny, cur.d, visited[cur.d][nx][ny]));
                }
            }
        }
        System.out.print(-1);
    }
}
