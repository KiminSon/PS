import java.io.*;
import java.util.*;

public class Main {

    static int n, a, b, m;
    static boolean[][] arr;
    static boolean[] visited;

    static int dfs(int x, int d) {
        if (x == b) {
            return d;
        }
        int tmp = -1;
        for (int i = 0; i < n; i++) {
            if (arr[x][i] && !visited[i]) {
                visited[i] = true;
                int k = dfs(i, d + 1);
                if (tmp == -1) {
                    tmp = k;
                }
            }
        }
        return tmp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken()) - 1;
        b = Integer.parseInt(st.nextToken()) - 1;
        m = Integer.parseInt(br.readLine());
        arr = new boolean[n][n];
        visited = new boolean[n];
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            arr[x][y] = true;
            arr[y][x] = true;
        }
        StringBuilder sb = new StringBuilder();
        visited[a] = true;
        sb.append(dfs(a, 0));
        System.out.print(sb);
    }
}
