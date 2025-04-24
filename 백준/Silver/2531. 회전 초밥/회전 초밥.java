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
            if (cnt[arr[i]]++ == 0) kind++;
        }

        int ans = kind + (cnt[c] == 0 ? 1 : 0);

        for (int i = 1; i < n; i++) {
            int out = arr[i - 1];
            int in = arr[(i + k - 1) % n];

            if (--cnt[out] == 0) kind--;
            if (++cnt[in] == 1) kind++;

            int total = kind + (cnt[c] == 0 ? 1 : 0);
            if (total > ans) ans = total;
        }

        System.out.println(ans);
    }
}
