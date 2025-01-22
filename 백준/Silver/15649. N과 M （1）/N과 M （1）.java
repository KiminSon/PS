import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static int n, m;
    private static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[] nums = new int[m];
        visited = new boolean[n + 1];
        f(0, 0, nums);
    }

    private static void f(int depth, int cnt, int[] nums) {
        if (depth == m) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < nums.length; i++) {
                sb.append(nums[i] + " ");
            }
            System.out.println(sb.toString());
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                nums[depth] = i;
                f(depth + 1, cnt + 1, nums);
                nums[depth] = 0;
                visited[i] = false;
            }
        }
    }
}