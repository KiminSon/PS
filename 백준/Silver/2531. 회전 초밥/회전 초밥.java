import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int[] cnt = new int[d + 1];
        int kind = 0;
        for (int i = 0; i < k; i++) {
            if (cnt[arr[i]]++ == 0)
                kind++;
        }

        int ans = kind;
        if (cnt[c] == 0) {
            ans++;
        }

        for (int i = 1; i < n; i++) {
            int s = arr[(i - 1) % n];
            int e = arr[(i + k - 1) % n];

            if (--cnt[s] == 0) {
                kind--;
            }
            if (++cnt[e] == 1) {
                kind++;
            }

            int total = kind + (cnt[c] == 0 ? 1 : 0);
            ans = Math.max(ans, total);
        }
        System.out.print(ans);
    }
}
