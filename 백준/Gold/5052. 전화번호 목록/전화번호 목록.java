import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Node {
        HashMap<Character, Node> child = new HashMap<>();
        boolean endOfWord = false;
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
                if (n.endOfWord) {
                    return true;
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
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            boolean flag = true;

            List<String> arr = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                String s = br.readLine();
                arr.add(s);
            }

            Collections.sort(arr);

            Trie trie = new Trie();

            for (int i = 0; i < n; i++) {
                String s = arr.get(i);
                boolean tmp = trie.search(s);
                if (tmp) {
                    flag = false;
                    break;
                }
                trie.insert(s);
            }

            if (flag) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }
        System.out.print(sb);
    }
}
