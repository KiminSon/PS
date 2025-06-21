import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] input = br.readLine().toCharArray();
        String tmp = "";
        int ans = 0;
        boolean minus = false;

        for (int i = 0; i < input.length; i++) {
            if ('0' <= input[i] && input[i] <= '9') {
                tmp += input[i];
            } else {
                if (minus) {
                    ans -= Integer.parseInt(tmp);
                } else {
                    ans += Integer.parseInt(tmp);
                }

                if (input[i] == '-') {
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
