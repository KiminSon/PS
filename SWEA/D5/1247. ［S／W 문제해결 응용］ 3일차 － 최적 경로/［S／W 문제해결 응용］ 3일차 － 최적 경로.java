import java.util.*;
import java.awt.*;
import java.io.*;

class Solution {

    static int n, ans, sx, sy, ex, ey;
    static int[][] arr;
    static int[] num;
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test_case;
        test_case = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int tc = 1; tc <= test_case; tc++) {
            ans = Integer.MAX_VALUE;
            n = Integer.parseInt(br.readLine());
            arr = new int[n][2];
            visited = new boolean[n];
            num = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            sx = Integer.parseInt(st.nextToken());
            sy = Integer.parseInt(st.nextToken());
            ex = Integer.parseInt(st.nextToken());
            ey = Integer.parseInt(st.nextToken());
            for (int i = 0; i < n; i++) {
                arr[i][0] = Integer.parseInt(st.nextToken());
                arr[i][1] = Integer.parseInt(st.nextToken());
            }
            f(0);
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.print(sb);
    }

    static void f(int d) {
        if (d == n) {
            int cnt = 0;
            for (int i = 0; i < n - 1; i++) {
                cnt += Math.abs(arr[num[i]][0] - arr[num[i + 1]][0]) + Math.abs(arr[num[i]][1] - arr[num[i + 1]][1]);
            }
            cnt += Math.abs(sx - arr[num[0]][0]) + Math.abs(sy - arr[num[0]][1]);
            cnt += Math.abs(ex - arr[num[n - 1]][0]) + Math.abs(ey - arr[num[n - 1]][1]);
            ans = Math.min(ans, cnt);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            num[d] = i;
            f(d + 1);
            visited[i] = false;
        }
    }
}