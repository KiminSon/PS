import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws Exception {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println("*");
            return;
        }
        arr = new int[4 * (n - 1) + 3][4 * (n - 1) + 1];

        f(0, 0, 4 * (n - 1) + 3);

        for (int i = 0; i < arr.length; i++) {
            if (i == 1) {
                sb.append("*");
                sb.append("\n");
                continue;
            }
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[i][j] == 1) {
                    sb.append("*");
                } else {
                    sb.append(" ");
                }
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

    private static void f(int x, int y, int n) {
        if (n == 7) {
            for (int i = 0; i < n; i++) {
                arr[x + i][y] = 1;
                arr[x + i][y + n - 3] = 1;
            }
            arr[x + 1][y + n - 3] = 0;
            arr[x + 2][y + n - 4] = 1;
            arr[x + 2][y + n - 5] = 1;
            for (int i = 0; i < n - 2; i++) {
                arr[x][y + i] = 1;
                arr[x + n - 1][y + i] = 1;
            }
            for (int i = 0; i < 3; i++) {
                arr[x + 2 + i][x + 2] = 1;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            arr[x + i][y] = 1;
            arr[x + i][y + n - 3] = 1;
        }
        arr[x + 1][y + n - 3] = 0;
        arr[x + 2][y + n - 4] = 1;
        arr[x + 2][y + n - 5] = 1;
        for (int i = 0; i < n - 2; i++) {
            arr[x][y + i] = 1;
            arr[x + n - 1][y + i] = 1;
        }

        f(x + 2, y + 2, n - 4);
    }

}