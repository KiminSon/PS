import java.io.*;
import java.util.*;

public class Main {

    static class Seg {
        long[] seg, arr;
        int size, l, r, idx;
        long val;

        Seg(int n) {
            size = n;
            int h = (int) Math.ceil(Math.log(n) / Math.log(2));
            int segSize = 2 << h;
            arr = new long[n];
            seg = new long[segSize];
        }

        void init(int n, int s, int e) {
            if (s == e) {
                seg[n] = arr[s];
                return;
            }
            int m = (s + e) / 2;
            init(n * 2, s, m);
            init(n * 2 + 1, m + 1, e);
            seg[n] = seg[n * 2] + seg[n * 2 + 1];
        }

        void segUpdate(int index, long value) {
            idx = index;
            val = value;
            update(1, 0, size - 1);
        }

        void update(int n, int s, int e) {
            if (idx < s || idx > e) {
                return;
            }
            if (s == e) {
                arr[s] = val;
                seg[n] = val;
                return;
            }
            int m = (s + e) / 2;
            update(n * 2, s, m);
            update(n * 2 + 1, m + 1, e);
            seg[n] = seg[n * 2] + seg[n * 2 + 1];
        }

        long segQuery(int left, int right) {
            l = left;
            r = right;
            return query(1, 0, size - 1);
        }

        long query(int n, int s, int e) {
            if (l > e || r < s) {
                return 0;
            }
            if (l <= s && e <= r) {
                return seg[n];
            }
            int m = (s + e) / 2;
            long lVal = query(n * 2, s, m);
            long rVal = query(n * 2 + 1, m + 1, e);
            return lVal + rVal;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken());
        Seg seg = new Seg(n);
        for (int i = 0; i < n; i++) {
            seg.arr[i] = Long.parseLong(br.readLine());
        }
        seg.init(1, 0, n - 1);
        StringBuilder sb = new StringBuilder();
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            if (a == 1) {
                int b = Integer.parseInt(st.nextToken());
                long c = Long.parseLong(st.nextToken());
                seg.segUpdate(b - 1, c);
            } else {
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                long tmp = seg.segQuery(b - 1, c - 1);
                sb.append(tmp).append('\n');
            }
        }
        System.out.print(sb);
    }
}