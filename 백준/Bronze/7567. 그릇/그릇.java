import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int cnt = 10;
        for (int i = 1; i < s.length(); i++) {
            char prev = s.charAt(i - 1);
            char cur = s.charAt(i);
            if (prev == '(' && cur == '(') {
                cnt += 5;
            }
            if (prev == '(' && cur == ')') {
                cnt += 10;
            }
            if (prev == ')' && cur == ')') {
                cnt += 5;
            }
            if (prev == ')' && cur == '(') {
                cnt += 10;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.println(sb.toString());
    }

}
