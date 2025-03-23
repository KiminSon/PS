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
            char move = s.charAt(i);
            int nx = x, ny = y;

            switch (move) {
                case 'R':
                    nx++;
                    break;
                case 'L':
                    nx--;
                    break;
                case 'U':
                    ny++;
                    break;
                case 'D':
                    ny--;
                    break;
            }

            if (!w.contains(nx * 1001 + ny)) {
                x = nx;
                y = ny;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(x - 500).append(' ').append(y - 500);
        System.out.print(sb);
    }
}
