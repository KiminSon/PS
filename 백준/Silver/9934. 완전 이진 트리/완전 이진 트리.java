import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] arr;
    static StringBuilder[] levels;

    static void dfs(int idx, int depth, int sz, int k) {
        levels[depth].append(arr[idx]).append(' ');

        if (depth == k) return;

        dfs(idx - sz, depth + 1, sz / 2, k);
        dfs(idx + sz, depth + 1, sz / 2, k);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        int n = 1 << k;
        arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        levels = new StringBuilder[k + 1];  // 깊이 k까지 존재
        for (int i = 1; i <= k; i++) {
            levels[i] = new StringBuilder();
        }

        dfs(n / 2, 1, n / 4, k);  // 루트 노드부터 시작

        for (int i = 1; i <= k; i++) {
            System.out.println(levels[i].toString().trim());
        }
    }
}
