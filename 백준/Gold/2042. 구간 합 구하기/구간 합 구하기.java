import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static long[] arr, segmentTree;
    static int left, right, index;
    static long value;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }

        int height = (int) Math.ceil(Math.log(n) / Math.log(2));
        int treeSize = 1 << (height + 1);
        segmentTree = new long[treeSize];
        init(1, 0, n - 1);

        for (int i = 0; i < m + k; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            if (a == 1) {
                index = Integer.parseInt(st.nextToken()) - 1;
                value = Long.parseLong(st.nextToken());
                update(1, 0, n - 1);
            } else {
                left = Integer.parseInt(st.nextToken()) - 1;
                right = Integer.parseInt(st.nextToken()) - 1;
                sb.append(query(1, 0, n - 1)).append("\n");
            }
        }
        System.out.print(sb);
    }

    static void init(int node, int start, int end) {
        if (start == end) {
            segmentTree[node] = arr[start];
        } else {
            init(node * 2, start, (start + end) / 2);
            init(node * 2 + 1, (start + end) / 2 + 1, end);
            segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
        }
    }

    static long query(int node, int start, int end) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && end <= right) {
            return segmentTree[node];
        }
        long leftSum = query(node * 2, start, (start + end) / 2);
        long rightSum = query(node * 2 + 1, (start + end) / 2 + 1, end);
        return leftSum + rightSum;
    }

    static void update(int node, int start, int end) {
        if (index < start || index > end) {
            return;
        }
        if (start == end) {
            arr[index] = value;
            segmentTree[node] = value;
            return;
        }
        update(node * 2, start, (start + end) / 2);
        update(node * 2 + 1, (start + end) / 2 + 1, end);
        segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
    }
}
