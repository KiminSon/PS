import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = n - i; j > 1; j--) {
                System.out.print(" ");
            }
            System.out.print("*");
            for (int j = 0; j < i * 2; j++) {
                System.out.print("*");
            }
            System.out.print("\n");
        }
        for (int i = n - 2; i > -1; i--) {
            for (int j = n - i; j > 1; j--) {
                System.out.print(" ");
            }
            System.out.print("*");
            for (int j = 0; j < i * 2; j++) {
                System.out.print("*");
            }
            System.out.print("\n");
        }
    }
}