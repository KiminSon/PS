import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String tmp = br.readLine();
        if (tmp.equals("brown")) {
            sb.append(1);
        } else if (tmp.equals("red")) {
            sb.append(2);
        } else if (tmp.equals("orange")) {
            sb.append(3);
        } else if (tmp.equals("yellow")) {
            sb.append(4);
        } else if (tmp.equals("green")) {
            sb.append(5);
        } else if (tmp.equals("blue")) {
            sb.append(6);
        } else if (tmp.equals("violet")) {
            sb.append(7);
        } else if (tmp.equals("grey")) {
            sb.append(8);
        } else if (tmp.equals("white")) {
            sb.append(9);
        }
        tmp = br.readLine();
        if (tmp.equals("brown")) {
            sb.append(1);
        } else if (tmp.equals("red")) {
            sb.append(2);
        } else if (tmp.equals("orange")) {
            sb.append(3);
        } else if (tmp.equals("yellow")) {
            sb.append(4);
        } else if (tmp.equals("green")) {
            sb.append(5);
        } else if (tmp.equals("blue")) {
            sb.append(6);
        } else if (tmp.equals("violet")) {
            sb.append(7);
        } else if (tmp.equals("grey")) {
            sb.append(8);
        } else if (tmp.equals("white")) {
            sb.append(9);
        } else {
            if (sb.length() == 0) {
                System.out.print(0);
                return;
            }
            sb.append(0);
        }
        tmp = br.readLine();
        if (tmp.equals("brown")) {
            sb.append('0');
        } else if (tmp.equals("red")) {
            sb.append("00");
        } else if (tmp.equals("orange")) {
            sb.append("000");
        } else if (tmp.equals("yellow")) {
            sb.append("0000");
        } else if (tmp.equals("green")) {
            sb.append("00000");
        } else if (tmp.equals("blue")) {
            sb.append("000000");
        } else if (tmp.equals("violet")) {
            sb.append("0000000");
        } else if (tmp.equals("grey")) {
            sb.append("00000000");
        } else if (tmp.equals("white")) {
            sb.append("000000000");
        }
        System.out.print(sb);
    }
}
