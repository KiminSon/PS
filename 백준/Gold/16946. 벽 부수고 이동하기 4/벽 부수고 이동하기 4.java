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
        boolean v[][] = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }

        Queue<int[]> q = new ArrayDeque<>();
        Queue<int[]> w = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sz = 0;
                if (arr[i][j] == 0 && !v[i][j]) {
                    q.add(new int[]{i, j});
                    v[i][j] = true;
                    sz++;
                    while (!q.isEmpty()) {
                        int[] cur = q.poll();
                        for (int k = 0; k < 4; k++) {
                            int nx = cur[0] + dx[k];
                            int ny = cur[1] + dy[k];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny]) {
                                continue;
                            }
                            v[nx][ny] = true;
                            if (arr[nx][ny] == 0) {
                                q.add(new int[]{nx, ny});
                                sz++;
                            } else {
                                w.add(new int[]{nx, ny});
                            }
                        }
                    }
                    while (!w.isEmpty()) {
                        int[] cur = w.poll();
                        arr[cur[0]][cur[1]] += sz;
                        v[cur[0]][cur[1]] = false;
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
