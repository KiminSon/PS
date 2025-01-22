import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static int n;
    private static int ans;
    private static boolean[] visited;
    private static int[] s;
    private static int[] a;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        s = new int[n];
        a = new int[n];
        ans = 2000000000;
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            s[i] = Integer.parseInt(st.nextToken());
            a[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 1; i <= n; i++) {
            f(i, 0, 1, 0);
        }
        System.out.print(ans);
    }

    private static void f(int m, int depth, int sc, int ac) {
        if (depth == m) {
            ans = Math.min(ans, Math.abs(sc - ac));
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                f(m, depth + 1, sc * s[i], ac + a[i]);
                visited[i] = false;
            }
        }
    }
}