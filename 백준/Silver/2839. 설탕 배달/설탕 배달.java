import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt = 0;
        while (true) {
            if (n % 5 == 0) {
                cnt += n / 5;
                break;
            }
            n -= 3;
            cnt++;
            if (n < 0) {
                System.out.print(-1);
                return;
            }
        }
        System.out.print(cnt);
    }
}
