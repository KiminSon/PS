import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Map<String, Boolean> mp = new HashMap<>();
        while (n-- > 0) {
            String s = br.readLine();
            mp.put(s, true);
        }
        int cnt = 0;

        while (m-- > 0) {
            String s = br.readLine();
            if (mp.containsKey(s)) {
                cnt++;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }
}
