import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static class Value {
        int min;
        int max;

        public Value(int min, int max) {
            this.min = min;
            this.max = max;
        }
    }

    static class SegmentTree {
        Value[] segmentTree, arr;
        int leafSize, left, right;

        SegmentTree(int initSize) {
            leafSize = initSize;
            int height = (int) Math.ceil(Math.log(initSize) / Math.log(2));
            int treeSize = 2 << height;
            arr = new Value[initSize];
            segmentTree = new Value[treeSize];
            Arrays.fill(segmentTree, new Value(Integer.MAX_VALUE, Integer.MIN_VALUE));
        }

        void init(int node, int start, int end) {
            if (start == end) {
                segmentTree[node] = new Value(arr[start].min, arr[start].max);
                return;
            }
            int mid = (start + end) / 2;
            init(node * 2, start, mid);
            init(node * 2 + 1, mid + 1, end);
            int minValue = Math.min(segmentTree[node * 2].min, segmentTree[node * 2 + 1].min);
            int maxValue = Math.max(segmentTree[node * 2].max, segmentTree[node * 2 + 1].max);
            segmentTree[node] = new Value(minValue, maxValue);
        }

        Value startQuery(int left, int right) {
            this.left = left;
            this.right = right;
            return query(1, 0, leafSize - 1);
        }

        Value query(int node, int start, int end) {
            if (left > end || right < start) {
                return new Value(Integer.MAX_VALUE, Integer.MIN_VALUE);
            }
            if (left <= start && end <= right) {
                return segmentTree[node];
            }
            int mid = (start + end) / 2;
            Value leftValue = query(node * 2, start, mid);
            Value rightValue = query(node * 2 + 1, mid + 1, end);
            int minValue = Math.min(leftValue.min, rightValue.min);
            int maxValue = Math.max(leftValue.max, rightValue.max);
            return new Value(minValue, maxValue);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        SegmentTree segmentTree = new SegmentTree(n);
        for (int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(br.readLine());
            segmentTree.arr[i] = new Value(tmp, tmp);
        }
        segmentTree.init(1, 0, n - 1);
        StringBuilder sb = new StringBuilder();
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            Value tmp = segmentTree.startQuery(a - 1, b - 1);
            sb.append(tmp.min).append(" ").append(tmp.max).append("\n");
        }
        System.out.print(sb);
    }
}
