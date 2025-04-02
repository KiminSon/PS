import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Pt {
        int idx, depth, sz;

        Pt(int idx, int depth, int sz) {
            this.idx = idx;
            this.depth = depth;
            this.sz = sz;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        int n = 1 << k;
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Queue<Pt> q = new ArrayDeque<>();
        q.add(new Pt(n / 2, 1, n / 4));

        int prev = 1;
        StringBuilder sb = new StringBuilder();

        while (!q.isEmpty()) {
            Pt cur = q.poll();
            int idx = cur.idx, depth = cur.depth, sz = cur.sz;

            if (prev < depth) {
                sb.append('\n');
                prev++;
            }

            sb.append(arr[idx]).append(' ');

            if (depth == k) continue;

            q.add(new Pt(idx - sz, depth + 1, sz / 2));
            q.add(new Pt(idx + sz, depth + 1, sz / 2));
        }

        System.out.print(sb);
    }
}
