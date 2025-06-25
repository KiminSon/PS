import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static int[] arr;
    static boolean[] visited;
    static StringBuilder sb = new StringBuilder();

    static void f(int d) {
        if (d == m) {
            for (int a : arr) {
                sb.append(a).append(' ');
            }
            sb.append('\n');
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[d] = i + 1;
                f(d + 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[m];
        visited = new boolean[n];

        f(0);
        System.out.print(sb);
    }
}
