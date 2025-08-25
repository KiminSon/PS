import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> mp = new HashMap<>();
        int mx = 0;
        String ans = "";
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            int cnt = mp.getOrDefault(s, 0) + 1;
            mp.put(s, cnt);

            if (cnt > mx) {
                mx = cnt;
                ans = s;
            } else if (cnt == mx && s.compareTo(ans) < 0) {
                ans = s;
            }
        }
        System.out.print(ans);
    }
}