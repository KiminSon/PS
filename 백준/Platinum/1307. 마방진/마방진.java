import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

    static int n;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());

        arr = new int[n][n];

        if (n % 2 == 1) {
            make3(sb);
        } else if (n % 4 == 0) {
            make4(sb);
        } else {
            make6(sb);
        }

        System.out.println(sb.toString());

    }

    public static void make3(StringBuilder sb) {
        int r = n - 1, c = n / 2;

        for (int i = 1; i <= n * n; i++) {
            arr[r][c] = i;

            if (arr[(r + 1) % n][(c + 1) % n] == 0) {
                r = (r + 1) % n;
                c = (c + 1) % n;
            } else {
                r--;
            }
        }

        print(sb);
    }

    public static void make4(StringBuilder sb) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = j + n * i + 1;
            }
        }

        for (int i = 0; i < n / 4; i++) {
            for (int j = n / 4; j < n / 4 * 3; j++) {
                int tmp = arr[i][j];
                arr[i][j] = arr[n - 1 - i][n - 1 - j];
                arr[n - 1 - i][n - 1 - j] = tmp;
            }
        }

        for (int i = n / 4; i < n / 4 * 3; i++) {
            for (int j = 0; j < n / 4; j++) {
                int tmp = arr[i][j];
                arr[i][j] = arr[n - 1 - i][n - 1 - j];
                arr[n - 1 - i][n - 1 - j] = tmp;
            }
        }

        print(sb);

    }

    public static void make6(StringBuilder sb) {
        int m = n / 2;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m / 2; j++) {
                if (i != m / 2) {
                    arr[i][j] = 3 * m * m;
                    arr[i + m][j] = 0;
                } else {
                    arr[i][j + 1] = 3 * m * m;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (i == m / 2) {
                arr[i + m][0] = 3 * m * m;
                for (int j = 1; j < m / 2 + 1; j++) {
                    arr[i][j] = 3 * m * m;
                }
                for (int j = m / 2 + 1; j < m; j++) {
                    arr[i + m][j] = 3 * m * m;
                }
            } else {
                for (int j = 0; j < m / 2; j++) {
                    arr[i][j] = 3 * m * m;
                }
                for (int j = m / 2; j < m; j++) {
                    arr[i + m][j] = 3 * m * m;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = m - (m / 2 - 1); j < m; j++) {
                arr[i][j + m] = m * m;
                arr[i + m][j + m] = 2 * m * m;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m - (m / 2 - 1); j++) {
                arr[i][j + m] = 2 * m * m;
                arr[i + m][j + m] = m * m;
            }
        }

        int[][] omd = new int[m][m];
        int r = m - 1;
        int c = m / 2;

        for (int i = 1; i <= m * m; i++) {
            omd[r][c] = i;

            if (omd[(r + 1) % m][(c + 1) % m] == 0) {
                r = (r + 1) % m;
                c = (c + 1) % m;
            } else {
                r--;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] += omd[i][j];
                arr[i][j + m] += omd[i][j];
                arr[i + m][j] += omd[i][j];
                arr[i + m][j + m] += omd[i][j];
            }
        }

        print(sb);
    }

    public static void print(StringBuilder sb) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(arr[i][j] + " ");
            }
            sb.append('\n');
        }
    }
}