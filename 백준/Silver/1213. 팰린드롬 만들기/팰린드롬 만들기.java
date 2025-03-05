import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[26];
        String s = br.readLine();
        char c = 'a';
        int sz = s.length();
        for (int i = 0; i < sz; i++) {
            arr[s.charAt(i) - 'A']++;
        }
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if ((arr[i] & 1) == 1) {
                odd++;
                c = (char) (i + 'A');
                arr[i]--;
            }
        }
        StringBuilder sb = new StringBuilder();
        if (odd > 1) {
            sb.append("I'm Sorry Hansoo");
        } else {
            for (int i = 0; i < 26; i++) {
                if (arr[i] != 0) {
                    for (int j = 0; j < arr[i] / 2; j++) {
                        sb.append((char) (i + 'A'));
                    }
                }
            }
            StringBuilder tmp = new StringBuilder(sb);
            if (c != 'a') {
                tmp.append(c);
            }
            sb.reverse();
            tmp.append(sb);

            sb = tmp;
        }
        System.out.print(sb);
    }

}
