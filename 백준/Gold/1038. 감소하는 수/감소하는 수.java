import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    static List<Long> arr = new ArrayList<>();

    static void f(long num, int d) {
        if (d == 10) {
            return;
        }
        arr.add(num);
        for (int i = 0; i < num % 10; i++) {
            f(num * 10 + i, d + 1);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        if (n > 1022) {
            System.out.print(-1);
        } else {
            for (int i = 0; i < 10; i++) {
                f(i, 0);
            }
            Collections.sort(arr);
            System.out.print(arr.get(n));
        }
    }
}
