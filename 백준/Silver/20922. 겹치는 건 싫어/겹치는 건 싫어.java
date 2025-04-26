import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        int[] cnt = new int[100001];
        st = new StringTokenizer(br.readLine());
        int ans = 0;
        int idx = 0;
        int sz = 0;
        int pt = 0;
        while (n-- > 0) {
            arr[idx] = Integer.parseInt(st.nextToken());
            sz++;
            cnt[arr[idx]]++;
            if (cnt[arr[idx]] > k) {
                while (true) {
                    if (arr[pt] == arr[idx]) {
                        cnt[arr[pt]]--;
                        pt++;
                        sz--;
                        break;
                    }
                    cnt[arr[pt]]--;
                    pt++;
                    sz--;
                }
            }
            ans = Math.max(ans, sz);
            idx++;
        }
        System.out.print(ans);
    }
}
