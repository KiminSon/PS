import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] input = br.readLine().toCharArray();
        byte[] count = new byte[26];
        byte length = (byte) input.length;

        for (char ch : input) {
            count[ch - 'A']++;
        }

        byte odd = 0;
        char oddChar = 0;
        for (int i = 0; i < 26; i++) {
            if ((count[i] & 1) == 1) {
                odd++;
                oddChar = (char) (i + 'A');
                if (odd > 1) {
                    System.out.print("I'm Sorry Hansoo");
                    return;
                }
            }
        }

        char[] result = new char[length];
        byte left = 0, right = (byte) (length - 1);

        for (int i = 0; i < 26; i++) {
            while (count[i] > 1) {
                result[left++] = (char) (i + 'A');
                result[right--] = (char) (i + 'A');
                count[i] -= 2;
            }
        }

        if (odd == 1) {
            result[left] = oddChar;
        }

        System.out.print(result);
    }
}
