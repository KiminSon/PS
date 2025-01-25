import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {

    static int n, m;
    static int[] arr, num;
    static boolean[] visited;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        num = new int[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(num);
        arr = new int[m];
        f(0, 0);
        System.out.println(sb.toString());
    }

    private static void f(int depth, int cnt) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                sb.append(arr[i] + " ");
            }
            sb.append("\n");
            return;
        }
        for (int i = cnt; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[depth] = num[cnt++];
                f(depth + 1, cnt);
                visited[i] = false;
            }
        }
    }
}