import java.io.*;
import java.util.*;

public class Main {

    static int n, m;
    static int[] arr;

    static boolean b(int h) {
        int p = 0;
        for (int i = 0; i < m; i++) {
            if (arr[i] - h <= p) {
                p = arr[i] + h;
            } else {
                return false;
            }
        }
        return n - p <= 0;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[m];
        for (int i = 0; i < m; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int l = 1, r = n, ans = 0;
        while (l <= r) {
            int md = (l + r) / 2;

            if (b(md)) {
                r = md - 1;
                ans = md;
            } else {
                l = md + 1;
            }
        }
        System.out.print(ans);
    }
}
