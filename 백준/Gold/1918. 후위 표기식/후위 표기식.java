import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String s = br.readLine();
        int sl = s.length();
        Deque<Character> st = new ArrayDeque<>();
        for (int i = 0; i < sl; i++) {
            char c = s.charAt(i);
            if ('A' <= c && c <= 'Z') {
                sb.append(c);
            } else {
                if (c == '(') {
                    st.offerLast(c);
                } else if (c == '*' || c == '/') {
                    while (!st.isEmpty() && (st.peekLast() == '*' || st.peekLast() == '/')) {
                        sb.append(st.pollLast());
                    }
                    st.offerLast(c);
                } else if (c == '+' || c == '-') {
                    while (!st.isEmpty() && st.peekLast() != '(') {
                        sb.append(st.pollLast());
                    }
                    st.offerLast(c);
                } else if (c == ')') {
                    while (!st.isEmpty() && st.peekLast() != '(') {
                        sb.append(st.pollLast());
                    }
                    st.pollLast();
                }
            }
        }

        while (!st.isEmpty()) {
            sb.append(st.pollLast());
        }

        System.out.print(sb);
    }
}
