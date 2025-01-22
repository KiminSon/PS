import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            arr[i] = tmp;
        }
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (arr[i] > m) {
                continue;
            }
            for (int j = i + 1; j < n - 1; j++) {
                if (arr[i] + arr[j] > m) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == m) {
                        System.out.println(m);
                        return;
                    }
                    if (arr[i] + arr[j] + arr[k] < m) {
                        ans = Math.max(ans, arr[i] + arr[j] + arr[k]);
                    }
                }
            }
        }
        System.out.println(ans);
    }

}