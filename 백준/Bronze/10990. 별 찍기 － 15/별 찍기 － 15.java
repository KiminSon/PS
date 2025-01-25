import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            if (i != n - 1) {
                for (int j = 0; j < n - i - 1; j++) {
                    sb.append(" ");
                }
            }
            sb.append("*");
            if (i != 0) {
                for (int j = 0; j < 2 * (i - 1) + 1; j++) {
                    sb.append(" ");
                }
                sb.append("*");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

}