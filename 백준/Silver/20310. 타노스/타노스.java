import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String s = br.readLine();
        int oc = 0;
        int zc = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                zc++;
            } else {
                oc++;
            }
        }
        sb.append("0".repeat(Math.max(0, zc / 2))).append("1".repeat(Math.max(0, oc / 2)));
        System.out.print(sb);
    }
}
