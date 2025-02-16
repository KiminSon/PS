import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static int[] cmp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        String str = br.readLine();
        arr = new int[4];
        cmp = new int[4];
        int cnt = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < p; i++) {
            if (str.charAt(i) == 'A') {
                cmp[0]++;
            }
            if (str.charAt(i) == 'C') {
                cmp[1]++;
            }
            if (str.charAt(i) == 'G') {
                cmp[2]++;
            }
            if (str.charAt(i) == 'T') {
                cmp[3]++;
            }
        }
        cnt += comp();
        for (int i = p; i < s; i++) {
            if (str.charAt(i) == 'A') {
                cmp[0]++;
            }
            if (str.charAt(i) == 'C') {
                cmp[1]++;
            }
            if (str.charAt(i) == 'G') {
                cmp[2]++;
            }
            if (str.charAt(i) == 'T') {
                cmp[3]++;
            }
            if (str.charAt(i - p) == 'A') {
                cmp[0]--;
            }
            if (str.charAt(i - p) == 'C') {
                cmp[1]--;
            }
            if (str.charAt(i - p) == 'G') {
                cmp[2]--;
            }
            if (str.charAt(i - p) == 'T') {
                cmp[3]--;
            }
            cnt += comp();
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }

    static int comp() {
        for (int i = 0; i < 4; i++) {
            if (cmp[i] < arr[i]) {
                return 0;
            }
        }
        return 1;
    }
}