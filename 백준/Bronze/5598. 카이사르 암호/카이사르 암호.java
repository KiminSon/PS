import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int sl = s.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < sl; i++) {
            sb.append((char) ((s.charAt(i) - 'A' + 23) % 26 + 'A'));
        }
        System.out.print(sb);
    }
}
