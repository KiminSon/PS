import java.util.*;
import java.io.*;

public class Main {

    static int r, c, jx, jy;
    static char[][] arr;
    static int[][] fv, jv;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new char[r][c];
        fv = new int[r][c];
        jv = new int[r][c];
        Queue<int[]> q = new LinkedList<>();

        for (int i = 0; i < r; i++) {
            String s = br.readLine();
            for (int j = 0; j < c; j++) {
                fv[i][j] = -1;
                jv[i][j] = -1;
                arr[i][j] = s.charAt(j);
                if (arr[i][j] == 'F') {
                    q.add(new int[]{i, j});
                    fv[i][j] = 0;
                }
                if (arr[i][j] == 'J') {
                    if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                        System.out.print(1);
                        return;
                    }
                    jx = i;
                    jy = j;
                    jv[i][j] = 0;
                }
            }
        }

        while (!q.isEmpty()) {
            int[] p = q.poll();
            int x = p[0], y = p[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] != '.' || fv[nx][ny] != -1) {
                    continue;
                }
                fv[nx][ny] = fv[x][y] + 1;
                q.add(new int[]{nx, ny});
            }
        }

        q.add(new int[]{jx, jy});
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int x = p[0], y = p[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] != '.' || jv[nx][ny] != -1) {
                    continue;
                }
                if (fv[nx][ny] != -1 && jv[x][y] + 1 >= fv[nx][ny]) {
                    continue;
                }
                jv[nx][ny] = jv[x][y] + 1;
                q.add(new int[]{nx, ny});
            }
        }

        int cnt = Integer.MAX_VALUE;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) && jv[i][j] != -1) {
                    cnt = Math.min(cnt, jv[i][j]);
                }
            }
        }

        if (cnt == Integer.MAX_VALUE) {
            System.out.print("IMPOSSIBLE");
        } else {
            System.out.println(cnt + 1);
        }
    }
}