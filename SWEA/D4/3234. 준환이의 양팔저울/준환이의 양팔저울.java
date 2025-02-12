import java.util.*;
import java.io.*;
 
class Solution {
 
    static int n, cnt;
    static int[] arr = new int[9];
    static boolean[] visited;
 
    public static void main(String args[]) throws Exception {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T;
        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            cnt = 0;
            n = Integer.parseInt(br.readLine());
            visited = new boolean[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            f(0, 0, 0);
            sb.append("#").append(tc).append(" ").append(cnt).append("\n");
        }
        System.out.print(sb);
    }
 
    static void f(int depth, int l, int r) {
        if (depth == n) {
            cnt++;
            return;
        }
 
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (l >= r + arr[i]) {
                    f(depth + 1, l, r + arr[i]);
                }
                f(depth + 1, l + arr[i], r);
                visited[i] = false;
            }
        }
    }
}