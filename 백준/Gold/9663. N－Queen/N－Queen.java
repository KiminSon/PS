import java.io.*;
import java.util.*;

public class Main {

    static int n, cnt;
    static int[] a;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        f(0);

        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }

    static void f(int x) {
        if (x == n) {
            cnt++;
            return;
        }
        for (int i = 0; i < n; i++) {
            a[x] = i;
            if (c(x)) {
                f(x + 1);
            }
        }
    }

    static boolean c(int x) {
        for (int i = 0; i < x; i++) {
            if (a[x] == a[i] || x - i == Math.abs(a[x] - a[i])) {
                return false;
            }
        }
        return true;
    }
}