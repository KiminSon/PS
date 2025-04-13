import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n, m, sx, sy;
    static char[][] arr;
    static boolean[][][] visited;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    static class Pt implements Comparable<Pt> {
        int key, x, y, cst;

        public Pt(int key, int x, int y, int cst) {
            this.key = key;
            this.x = x;
            this.y = y;
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
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new char[n][m];
        visited = new boolean[64][n][m];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j);
                if (arr[i][j] == '0') {
                    sx = i;
                    sy = j;
                }
            }
        }
        PriorityQueue<Pt> pq = new PriorityQueue<>();
        pq.add(new Pt(0, sx, sy, 0));
        visited[0][sx][sy] = true;
        while (!pq.isEmpty()) {
            Pt pt = pq.poll();
            int key = pt.key;
            int x = pt.x;
            int y = pt.y;
            int cst = pt.cst;
            if (arr[x][y] == '1') {
                System.out.print(cst);
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                char cur = arr[nx][ny];
                if (cur == '#') {
                    continue;
                }
                if ('a' <= cur && cur <= 'f') {
                    int curKey = key | (1 << (cur - 'a'));
                    if (!visited[curKey][nx][ny]) {
                        visited[curKey][nx][ny] = true;
                        pq.add(new Pt(curKey, nx, ny, cst + 1));
                    }
                } else if ('A' <= cur && cur <= 'F') {
                    int curKey = (1 << (cur - 'A'));
                    if ((key & curKey) == curKey && !visited[key][nx][ny]) {
                        visited[key][nx][ny] = true;
                        pq.add(new Pt(key, nx, ny, cst + 1));
                    }
                } else {
                    if (!visited[key][nx][ny]) {
                        visited[key][nx][ny] = true;
                        pq.add(new Pt(key, nx, ny, cst + 1));
                    }
                }
            }
        }
        System.out.print(-1);
    }
}
