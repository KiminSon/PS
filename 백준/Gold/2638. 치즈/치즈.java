import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

    static int[][] arr, visited;
    static int n, m, cnt = -1;
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while (true) {
            boolean flag = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] > 2) {
                        flag = true;
                        arr[i][j] = 0;
                    } else if (arr[i][j] > 0) {
                        flag = true;
                        arr[i][j] = 1;
                    }
                }
            }

            if (flag == false) {
                break;
            }

            visited = new int[n][m];
            Queue<Point> q = new LinkedList<>();
            visited[0][0] = 1;
            q.add(new Point(0, 0));
            while (!q.isEmpty()) {
                int x = q.peek().x;
                int y = q.peek().y;
                q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] == 1) {
                        continue;
                    }
                    if (arr[nx][ny] >= 1) {
                        arr[nx][ny]++;
                    } else {
                        visited[nx][ny] = 1;
                        q.add(new Point(nx, ny));
                    }
                }
            }
            cnt++;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }
}