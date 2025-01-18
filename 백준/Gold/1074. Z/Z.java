import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

    static int k = 0;
    static int r, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[0]);
        r = Integer.parseInt(input[1]);
        c = Integer.parseInt(input[2]);

        f((int) Math.pow(2, n), 0, 0);
    }

    private static void f(int n, int x, int y) {
        if (y == r && x == c) {
            StringBuilder sb = new StringBuilder();
            sb.append(k);
            System.out.print(sb.toString());
            return;
        }
        if (x <= c && c < x + n && y <= r && r < y + n) {
            f(n / 2, x, y);
            f(n / 2, x + n / 2, y);
            f(n / 2, x, y + n / 2);
            f(n / 2, x + n / 2, y + n / 2);
        } else {
            k += n * n;
        }

    }
}