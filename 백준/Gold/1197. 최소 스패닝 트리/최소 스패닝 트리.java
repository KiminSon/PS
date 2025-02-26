import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int vertex, edge, answer = 0;
    static PriorityQueue<Node> pq = new PriorityQueue<>();
    static int[] union, range;

    static class Node implements Comparable<Node> {
        int start;
        int end;
        int weight;

        public Node(int start, int end, int weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        vertex = Integer.parseInt(st.nextToken());
        edge = Integer.parseInt(st.nextToken());
        for (int i = 0; i < edge; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            pq.offer(new Node(start, end, weight));
        }
        init();
        int connection = 0;
        while (connection < vertex - 1) {
            Node node = pq.poll();
            if (unite(node.start, node.end)) {
                connection++;
                answer += node.weight;
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(answer);
        System.out.print(answer);
    }

    static void init() {
        union = new int[vertex + 1];
        range = new int[vertex + 1];
        for (int i = 1; i <= vertex; i++) {
            union[i] = i;
            range[i] = 1;
        }
    }

    static boolean unite(int a, int b) {
        a = findUnion(a);
        b = findUnion(b);
        if (a == b) {
            return false;
        }
        if (range[a] < range[b]) {
            range[b] += range[a];
            union[a] = b;
        } else {
            range[a] += range[b];
            union[b] = a;
        }
        return true;
    }

    static int findUnion(int target) {
        if (target == union[target]) {
            return union[target];
        }
        return union[target] = findUnion(union[target]);
    }
}