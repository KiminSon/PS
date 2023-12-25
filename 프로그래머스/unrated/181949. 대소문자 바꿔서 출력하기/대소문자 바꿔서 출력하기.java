import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        for(int i = 0; i< a.length(); i++){
            int tmp = (int)a.charAt(i);
            if(tmp >= 65 && tmp <= 90)
                System.out.print((char)(tmp + 32));
            else
                System.out.print((char)(tmp - 32));
        }
    }
}