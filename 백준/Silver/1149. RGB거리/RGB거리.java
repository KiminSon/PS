import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        while (--n > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) + Math.min(b, c);
            int y = Integer.parseInt(st.nextToken()) + Math.min(a, c);
            int z = Integer.parseInt(st.nextToken()) + Math.min(a, b);
            a = x;
            b = y;
            c = z;
        }
        System.out.print(Math.min(a, Math.min(b, c)));
    }
}
