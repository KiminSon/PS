import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws Exception {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        arr[n / 2][n / 2] = 1;
        int fin = n * n;
        int cnt = 2;
        int x = n / 2 - 1, y = n / 2;
        int mx = 0, my = 0;
        if (m == 1) {
            mx = n / 2 + 1;
            my = n / 2 + 1;
        }
        if (m == n * n) {
            mx = 1;
            my = 1;
        }
        int dir = 0;
        while (true) {
            arr[x][y] = cnt;
            if (cnt == m) {
                mx = x + 1;
                my = y + 1;
            }
            cnt++;
            if (dir % 4 == 0) {
                if (arr[x + 1][y] == 0) {
                    dir++;
                    x++;
                } else {
                    y++;
                }
            } else if (dir % 4 == 1) {
                if (arr[x][y - 1] == 0) {
                    dir++;
                    y--;
                } else {
                    x++;
                }
            } else if (dir % 4 == 2) {
                if (arr[x - 1][y] == 0) {
                    dir++;
                    x--;
                } else {
                    y--;
                }
            } else if (dir % 4 == 3) {
                if (arr[x][y + 1] == 0) {
                    dir++;
                    y++;
                } else {
                    x--;
                }
            }
            if (cnt == fin) {
                arr[x][y] = cnt;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != n - 1) {
                    sb.append(arr[i][j] + " ");
                } else {
                    sb.append(arr[i][j]);
                }
            }
            sb.append("\n");
        }
        sb.append(mx + " " + my);
        System.out.println(sb.toString());
    }
}