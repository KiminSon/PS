import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        boolean[][] arr = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = tmp.charAt(j) == '1';
            }
        }

        boolean[][][] visited = new boolean[n][m][2];
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{0, 0, 1, 0});
        visited[0][0][0] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1], d = cur[2], w = cur[3];

            if (x == n - 1 && y == m - 1) {
                System.out.println(d);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                if (!arr[nx][ny] && !visited[nx][ny][w]) {
                    q.add(new int[]{nx, ny, d + 1, w});
                    visited[nx][ny][w] = true;
                }

                if (arr[nx][ny] && w == 0 && !visited[nx][ny][1]) {
                    q.add(new int[]{nx, ny, d + 1, 1});
                    visited[nx][ny][1] = true;
                }
            }
        }

        System.out.println(-1);
    }
}
