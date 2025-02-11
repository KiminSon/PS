import java.util.*;
import java.io.*;

public class Main {

    static int n, mn = 1000000;
    static int[][] arr;
    static int[] p, team, visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        p = new int[n];
        arr = new int[n][n];
        team = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int tmp = Integer.parseInt(st.nextToken());
            for (int j = 0; j < tmp; j++) {
                arr[i][Integer.parseInt(st.nextToken()) - 1] = 1;
            }
        }
        subset(0);
        if (mn == 1000000) {
            mn = -1;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(mn);
        System.out.println(sb);
    }

    static void subset(int depth) {
        if (depth == n) {
            int r = -1, l = -1;
            int rcnt = 0, lcnt = 0;
            for (int i = 0; i < n; i++) {
                if (team[i] == 0) {
                    r = i;
                    rcnt += p[i];
                }
                if (team[i] == 1) {
                    l = i;
                    lcnt += p[i];
                }
            }
            if (r == -1 || l == -1) {
                return;
            }
            visited = new int[n];

            dfs(r);
            dfs(l);

            for (int i = 0; i < n; i++) {
                if (visited[i] == 0) {
                    return;
                }
            }

            mn = Math.min(mn, Math.abs(lcnt - rcnt));
            return;
        }

        subset(depth + 1);
        team[depth] = 1;
        subset(depth + 1);
        team[depth] = 0;
    }

    static void dfs(int x) {
        visited[x] = 1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && arr[x][i] == 1 && team[x] == team[i]) {
                dfs(i);
            }
        }
    }
}