import java.io.*;
import java.util.*;

public class Main {

    static class pt implements Comparable<pt> {
        int st;
        int ed;

        public pt(int st, int ed) {
            this.st = st;
            this.ed = ed;
        }

        @Override
        public int compareTo(pt o) {
            if (this.ed == o.ed) {
                return Integer.compare(this.st, o.st);
            }
            return Integer.compare(this.ed, o.ed);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        pt[] arr = new pt[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[i] = new pt(a, b);
        }
        Arrays.sort(arr);
        int cnt = 0, cur = -1;
        for (pt i : arr) {
            if (i.st >= cur) {
                cur = i.ed;
                cnt++;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }
}