import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int arr[][] = new int[n][m];
        int v[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }

        Queue<int[]> q = new ArrayDeque<>();
        Queue<int[]> w = new ArrayDeque<>();
        int d = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sz = 0;
                if (arr[i][j] == 0 && v[i][j] == 0) {
                    d++;
                    q.add(new int[]{i, j});
                    v[i][j] = d;
                    sz++;
                    while (!q.isEmpty()) {
                        int[] cur = q.poll();
                        for (int k = 0; k < 4; k++) {
                            int nx = cur[0] + dx[k];
                            int ny = cur[1] + dy[k];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                                continue;
                            }
                            if (arr[nx][ny] == 0 && v[nx][ny] == 0) {
                                v[nx][ny] = d;
                                q.add(new int[]{nx, ny});
                                sz++;
                            }
                            if (arr[nx][ny] != 0 && v[nx][ny] != d) {
                                v[nx][ny] = d;
                                w.add(new int[]{nx, ny});
                            }
                        }
                    }
                    while (!w.isEmpty()) {
                        int[] cur = w.poll();
                        arr[cur[0]][cur[1]] += sz;
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sb.append(arr[i][j] % 10);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
