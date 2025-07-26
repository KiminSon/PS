import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int ans = 0;
        int idx1 = 0, idx2 = 0;
        int n = Integer.parseInt(br.readLine());
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = Math.min(arr[i].length(), arr[j].length());
                int cnt = 0;
                for (int k = 0; k < len; k++) {
                    if (arr[i].charAt(k) != arr[j].charAt(k)) break;
                    cnt++;
                }
                if (cnt > ans || (cnt == ans && i < idx1)) {
                    ans = cnt;
                    idx1 = i;
                    idx2 = j;
                }
            }
        }

        System.out.println(arr[idx1]);
        System.out.print(arr[idx2]);
    }
}
