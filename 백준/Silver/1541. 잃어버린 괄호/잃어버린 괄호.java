import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        String tmp = "";
        int ans = 0;
        boolean minus = false;

        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if ('0' <= c && c <= '9') {
                tmp += c;
            } else {
                if (minus) {
                    ans -= Integer.parseInt(tmp);
                } else {
                    ans += Integer.parseInt(tmp);
                }

                if (c == '-') {
                    minus = true;
                }

                tmp = "";
            }
        }

        if (minus) {
            ans -= Integer.parseInt(tmp);
        } else {
            ans += Integer.parseInt(tmp);
        }

        System.out.print(ans);
    }
}
