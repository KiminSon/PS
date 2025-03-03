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
        PriorityQueue<pt> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            pq.add(new pt(a, b));
        }
        int cnt = 0, cur = -1;
        for (int i = 0; i < n; i++) {
            pt tmp = pq.poll();
            if (tmp.st >= cur) {
                cur = tmp.ed;
                cnt++;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(cnt);
        System.out.print(sb);
    }
}