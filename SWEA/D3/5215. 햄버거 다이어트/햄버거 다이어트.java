import java.util.*;
import java.io.*;

class Solution {
    static int[][] arr;
    static int mx, n, l;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T;
        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            l = Integer.parseInt(st.nextToken());
            arr = new int[n][2];
            mx = 0;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                arr[i][0] = Integer.parseInt(st.nextToken());
                arr[i][1] = Integer.parseInt(st.nextToken());
            }
            subset(0, 0, 0);
            sb.append("#").append(tc).append(" ").append(mx).append("\n");
        }
        System.out.print(sb);
    }

    static void subset(int depth, int fav, int cost) {
        if (cost > l) {
            return;
        }
        if (depth == n) {
            mx = Math.max(mx, fav);
            return;
        }
        mx = Math.max(mx, fav);
        subset(depth + 1, fav + arr[depth][0], cost + arr[depth][1]);
        subset(depth + 1, fav, cost);
    }
}