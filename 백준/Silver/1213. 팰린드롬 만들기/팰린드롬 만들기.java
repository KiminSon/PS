import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[26];
        String s = br.readLine();
        int sz = s.length();
        
        for (int i = 0; i < sz; i++) {
            arr[s.charAt(i) - 'A']++;
        }

        int odd = 0;
        char oddChar = 0;
        for (int i = 0; i < 26; i++) {
            if ((arr[i] & 1) == 1) {
                odd++;
                oddChar = (char) (i + 'A');
                if (odd > 1) {
                    System.out.print("I'm Sorry Hansoo");
                    return;
                }
                arr[i]--;
            }
        }
        
        char[] result = new char[sz];
        int left = 0, right = sz - 1;
        
        for (int i = 0; i < 26; i++) {
            while (arr[i] > 0) {
                result[left++] = (char) (i + 'A');
                result[right--] = (char) (i + 'A');
                arr[i] -= 2;
            }
        }

        if (oddChar != 0) {
            result[left] = oddChar;
        }

        System.out.print(result);
    }
}
