import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int x = 500, y = 500;
        Set<Integer> w = new HashSet<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) + 500;
            int b = Integer.parseInt(st.nextToken()) + 500;
            w.add(a * 1001 + b);
        }
        String s = br.readLine();
        for (int i = 0; i < k; i++) {
            int nx = x;
            int ny = y;

            if (s.charAt(i) == 'R') {
                nx++;
                if (w.contains(nx * 1001 + ny)) {
                    continue;
                }
                x = nx;
            } else if (s.charAt(i) == 'L') {
                nx--;
                if (w.contains(nx * 1001 + ny)) {
                    continue;
                }
                x = nx;
            } else if (s.charAt(i) == 'U') {
                ny++;
                if (w.contains(nx * 1001 + ny)) {
                    continue;
                }
                y = ny;
            } else {
                ny--;
                if (w.contains(nx * 1001 + ny)) {
                    continue;
                }
                y = ny;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(x - 500).append(' ').append(y - 500);
        System.out.print(sb);
    }
}
