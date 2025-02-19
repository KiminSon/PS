import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[][] dir = new boolean[n][n];
        int[] conn = new int[n];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            dir[a - 1][b - 1] = true;
            conn[a - 1]++;
            conn[b - 1]++;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dir[i][k] && dir[k][j] && !dir[i][j]) {
                        dir[i][j] = true;
                        conn[i]++;
                        conn[j]++;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (conn[i] == n - 1) {
                cnt++;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }
}