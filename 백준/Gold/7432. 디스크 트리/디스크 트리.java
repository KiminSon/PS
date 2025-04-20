import java.io.*;
import java.util.*;

public class Main {

    static StringBuilder sb = new StringBuilder();

    static class Trie {
        Map<String, Trie> child = new HashMap<>();

        void insert(String s) {
            Trie trie = this;
            String[] str = s.split("\\\\");
            for (String i : str) {
                trie.child.putIfAbsent(i, new Trie());
                trie = trie.child.get(i);
            }
        }

        void print(Trie cur, int d) {
            if (cur.child != null) {
                List<String> arr = new ArrayList<>(cur.child.keySet());
                Collections.sort(arr);
                for (String s : arr) {
                    for (int i = 0; i < d; i++) {
                        sb.append(' ');
                    }
                    sb.append(s).append('\n');
                    print(cur.child.get(s), d + 1);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Trie trie = new Trie();
        while (n-- > 0) {
            trie.insert(br.readLine());
        }
        trie.print(trie, 0);
        System.out.print(sb);
    }
}