import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int sl = s.length();
        Deque<Double> st = new ArrayDeque<>();
        for (int i = 0; i < sl; i++) {
            char c = s.charAt(i);
            if ('A' <= c && c <= 'Z') {
                st.offerLast((double) arr[c - 'A']);
            } else if (c == '*') {
                double tmp1 = st.pollLast();
                double tmp2 = st.pollLast();
                st.offerLast((double) tmp2 * tmp1);
            } else if (c == '/') {
                double tmp1 = st.pollLast();
                double tmp2 = st.pollLast();
                st.offerLast((double) tmp2 / tmp1);
            } else if (c == '+') {
                double tmp1 = st.pollLast();
                double tmp2 = st.pollLast();
                st.offerLast((double) tmp2 + tmp1);
            } else if (c == '-') {
                double tmp1 = st.pollLast();
                double tmp2 = st.pollLast();
                st.offerLast((double) tmp2 - tmp1);
            }
        }
        System.out.printf("%.2f", st.pollLast());
    }
}
