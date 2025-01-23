import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static char[][] arr;
    private static int n, m, cnt = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            f(i, 0);
        }

        System.out.print(cnt);
    }

    private static boolean f(int x, int y) {
        if (y == m - 1) {
            arr[x][y] = 'x';
            cnt++;
            return true;
        }

        boolean b = false;
        if (x - 1 >= 0 && arr[x - 1][y + 1] == '.') {
            arr[x - 1][y + 1] = 'x';
            b = f(x - 1, y + 1);
        }

        if (b == false && arr[x][y + 1] == '.') {
            arr[x][y + 1] = 'x';
            b = f(x, y + 1);
        }

        if (b == false && x + 1 < n && arr[x + 1][y + 1] == '.') {
            arr[x + 1][y + 1] = 'x';
            b = f(x + 1, y + 1);
        }
        return b;
    }
}