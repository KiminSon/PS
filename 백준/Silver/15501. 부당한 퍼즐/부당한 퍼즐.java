import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        Deque<Integer> dq = new ArrayDeque<>();
        Deque<Integer> rdq = new ArrayDeque<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            dq.addFirst(tmp);
            rdq.addLast(tmp);
        }
        int tmp = arr[0];
        while (true) {
            if (dq.peekFirst() == tmp) {
                break;
            }
            dq.addLast(dq.pollFirst());
        }
        while (true) {
            if (rdq.peekFirst() == tmp) {
                break;
            }
            rdq.addLast(rdq.pollFirst());
        }
        boolean fg = true, rfg = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] != dq.pollFirst()) {
                fg = false;
            }
            if (arr[i] != rdq.pollFirst()) {
                rfg = false;
            }
        }
        StringBuilder sb = new StringBuilder();
        if (fg || rfg) {
            sb.append("good puzzle");
        } else {
            sb.append("bad puzzle");
        }
        System.out.print(sb);
    }

}
