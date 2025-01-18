import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        arr = new int[n][2 * n];

        f(n, 0, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                if (arr[i][j] == 1) {
                    sb.append("*");
                } else {
                    sb.append(" ");
                }
            }
            sb.append("\n");
        }

        System.out.print(sb.toString());
    }

    private static void f(int n, int x, int y) {
        if (n == 3) {
            arr[y][x + 2] = 1;
            arr[y + 1][x + 1] = 1;
            arr[y + 1][x + 3] = 1;
            for (int i = 0; i < 5; i++) {
                arr[y + 2][x + i] = 1;
            }
            return;
        }
        f(n / 2, x + n / 2, y);
        f(n / 2, x, y + n / 2);
        f(n / 2, x + n, y + n / 2);
    }
}