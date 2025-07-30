import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] c = br.readLine().toCharArray();
        int n = c.length;
        boolean[] b = new boolean[c.length];
        int zcnt = 0, ocnt = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] == '0') {
                zcnt++;
            } else {
                ocnt++;
            }
        }
        zcnt /= 2;
        ocnt /= 2;
        int idx = 0;
        for (int i = 0; i < ocnt; i++) {
            if (c[idx++] == '1') {
                b[idx - 1] = true;
            } else {
                i--;
            }
        }
        idx = n - 1;
        for (int i = 0; i < zcnt; i++) {
            if (c[idx--] == '0') {
                b[idx + 1] = true;
            } else {
                i--;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (!b[i]) {
                sb.append(c[i]);
            }
        }
        System.out.print(sb);
    }
}
