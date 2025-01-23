import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] p;
    static int N, R;
    static int[] nums;
    static boolean[] visited;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        p = new int[N];
        for (int i = 0; i < N; i++) {
            p[i] = i + 1;
        }
        nums = new int[R];
        visited = new boolean[N];
        perm(0, 0);
        System.out.print(sb.toString());
    }

    private static void perm(int cnt, int start) {
        if (R == cnt) {
            for (int i = 0; i < cnt; i++) {
                sb.append(nums[i] + " ");
            }
            sb.append("\n");
            return;
        }

        for (int i = start; i < N; i++) {
            visited[i] = true;
            nums[cnt] = p[i];
            perm(cnt + 1, i + 1);
            nums[cnt] = 0;
            visited[i] = false;
        }
    }

}