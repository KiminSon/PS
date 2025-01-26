import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws Exception {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int h = (1 << n) - 1;
        int w = 2 * h - 1;
        arr = new int[h][w];

        boolean dir = false;
        if (n % 2 == 0) {
            dir = true;
        }
        int x = 0;
        if (dir) {
            x = (1 << n) - 2;
        }
        int y = (1 << n) - 2;

        f(n, x, y, dir);

        if (dir) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (arr[i][j] == 1) {
                        sb.append("*");
                    } else {
                        sb.append(" ");
                    }
                }
                w--;
                sb.append("\n");
            }
        } else {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j <= y; j++) {
                    if (arr[i][j] == 1) {
                        sb.append("*");
                    } else {
                        sb.append(" ");
                    }
                }
                y++;
                sb.append("\n");
            }
        }
        System.out.println(sb.toString());
    }

    private static void f(int n, int x, int y, boolean dir) {
        arr[x][y] = 1;
        if (n == 1) {
            return;
        }
        int h = (1 << n) - 1;
        int l = y;
        int r = y;

        for (int i = 1; i < h; i++) {
            if (dir) {
                x--;
            } else {
                x++;
            }
            l--;
            r++;
            arr[x][l] = 1;
            arr[x][r] = 1;
        }

        for (int i = l + 1; i < r; i++) {
            arr[x][i] = 1;
        }

        if (dir) {
            x++;
        } else {
            x--;
        }

        f(n - 1, x, y, !dir);

    }

}