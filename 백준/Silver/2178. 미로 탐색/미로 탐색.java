import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static int[][] arr;
    static int[][] visited;
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };

    public static class loc {
        int x;
        int y;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n + 1][m + 1];
        visited = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            for (int j = 1; j <= m; j++) {
                char c;
                c = s.charAt(j - 1);
                arr[i][j] = c - '0';
            }
        }
        Queue<loc> q = new LinkedList<>();
        loc l;
        l = new loc();
        l.x = 1;
        l.y = 1;
        visited[l.x][l.y] = 1;
        q.add(l);
        while (!q.isEmpty()) {
            loc cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m) {
                    continue;
                }
                if (visited[nx][ny] != 0 || arr[nx][ny] == 0) {
                    continue;
                }
                visited[nx][ny] = visited[cur.x][cur.y] + 1;
                loc tmp = new loc();
                tmp.x = nx;
                tmp.y = ny;
                q.add(tmp);
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(visited[n][m]);
        System.out.print(sb.toString());
    }
}