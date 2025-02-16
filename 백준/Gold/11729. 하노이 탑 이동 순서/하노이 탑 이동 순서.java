import java.math.*;
import java.io.*;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        BigInteger bi = new BigInteger("1");
        BigInteger bitwo = new BigInteger("2");
        BigInteger bione = new BigInteger("1");
        for (int i = 0; i < n; i++) {
            bi = bi.multiply(bitwo);
        }
        bi = bi.subtract(bione);
        sb.append(bi).append("\n");

        if (n <= 20) {
            h(1, 2, 3, n);
        }

        System.out.print(sb);
    }

    static void h(int s, int m, int e, int n) {
        if (n == 1) {
            sb.append(s).append(" ").append(e).append("\n");

        } else {
            h(s, e, m, n - 1);
            sb.append(s).append(" ").append(e).append("\n");
            h(m, s, e, n - 1);
        }
    }
}