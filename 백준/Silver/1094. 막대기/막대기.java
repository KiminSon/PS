import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int ans = 0;
        int n = in.nextInt();
        while (true) {
            if (64 == n) {
                ans++;
                break;
            }
            if (n >= 32) {
                ans++;
                n -= 32;
            }
            if (n >= 16) {
                ans++;
                n -= 16;
            }
            if (n >= 8) {
                ans++;
                n -= 8;
            }
            if (n >= 4) {
                ans++;
                n -= 4;
            }
            if (n >= 2) {
                ans++;
                n -= 2;
            }
            if (n >= 1) {
                ans++;
                n -= 1;
            }
            if (n == 0) {
                break;
            }
        }
        System.out.println(ans);
    }
}