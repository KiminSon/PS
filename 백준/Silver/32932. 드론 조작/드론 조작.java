import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int x = 0, y = 0;
        Set<String> w = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            w.add(a + "," + b);
        }
        String s = br.readLine();
        for (int i = 0; i < k; i++) {
            int nx = x;
            int ny = y;

            if (s.charAt(i) == 'R') {
                nx++;
                if (w.contains(nx + "," + ny)) {
                    continue;
                }
                x = nx;
            }

            if (s.charAt(i) == 'L') {
                nx--;
                if (w.contains(nx + "," + ny)) {
                    continue;
                }
                x = nx;
            }

            if (s.charAt(i) == 'U') {
                ny++;
                if (w.contains(nx + "," + ny)) {
                    continue;
                }
                y = ny;
            }

            if (s.charAt(i) == 'D') {
                ny--;
                if (w.contains(nx + "," + ny)) {
                    continue;
                }
                y = ny;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(x).append(' ').append(y);
        System.out.print(sb);
    }
}
