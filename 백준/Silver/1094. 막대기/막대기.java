import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = 64, cnt = 0, x = Integer.parseInt(br.readLine());
        while (x > 0) {
            if (x >= n) {
                x -= n;
                cnt++;
            }
            n >>= 1;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }
}