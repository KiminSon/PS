import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Node {
        HashMap<Character, Node> child = new HashMap<>();
        boolean endOfWord = true;
    }

    static class Trie {
        Node root = new Node();

        public void insert(String s) {
            Node n = root;

            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                n.child.putIfAbsent(c, new Node());
                n = n.child.get(c);
            }

            n.endOfWord = true;
        }

        boolean search(String s) {
            Node n = root;

            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);

                if (n.child.containsKey(c)) {
                    n = n.child.get(c);
                } else {
                    return false;
                }
            }
            return n.endOfWord;
        }

        boolean trieDelete(String s) {
            return delete(root, s, 0);
        }

        boolean delete(Node n, String s, int idx) {
            char c = s.charAt(idx);

            if (!n.child.containsKey(c)) {
                return false;
            }

            Node cur = n.child.get(c);
            idx++;
            if (idx == s.length()) {
                if (!cur.endOfWord) {
                    return false;
                }
                cur.endOfWord = false;

                if (cur.child.isEmpty()) {
                    n.child.remove(c);
                }
            } else {
                if (!delete(cur, s, idx)) {
                    return false;
                }

                if (!cur.endOfWord && cur.child.isEmpty()) {
                    n.child.remove(c);
                }
            }

            return true;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        Trie t = new Trie();
        while (n-- > 0) {
            t.insert(br.readLine());
        }
        int cnt = 0;
        while (m-- > 0) {
            if (t.search(br.readLine())) {
                cnt++;
            }
        }

        sb.append(cnt);
        System.out.print(sb);
    }
}