import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        int x = Integer.parseInt(br.readLine());
        int s = 0;
        int e = n - 1;
        int cnt = 0;
        while (true) {
            if (s == e) {
                break;
            }
            if (arr[s] + arr[e] == x) {
                cnt++;
                s++;
            } else if (arr[s] + arr[e] < x) {
                s++;
            } else {
                e--;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }
}