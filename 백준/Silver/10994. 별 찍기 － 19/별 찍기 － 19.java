import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws Exception {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[4 * (n - 1) + 1][4 * (n - 1) + 1];

        f(0, 0, 4 * (n - 1) + 1);

        for (int i = 0; i < arr.length; i++) {
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
        if (n == 1) {
            arr[x][y] = 1;
            return;
        }

        for (int i = 0; i < n; i++) {
            arr[x][y + i] = 1;
            arr[x + n - 1][y + i] = 1;
            arr[x + i][y] = 1;
            arr[x + i][y + n - 1] = 1;
        }

        f(x + 2, y + 2, n - 4);
    }

}