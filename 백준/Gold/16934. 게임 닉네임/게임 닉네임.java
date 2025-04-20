import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        HashMap<Character, Node> child = new HashMap<>();
        int count = 0;
        boolean end = false;
    }

    static class Trie {
        Node root = new Node();

        String insert(String s) {
            Node node = root;
            StringBuilder sb = new StringBuilder();
            String result = null;

            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                sb.append(c);

                node.child.putIfAbsent(c, new Node());
                node = node.child.get(c);
                node.count++;

                if (result == null && node.count == 1) {
                    result = sb.toString();
                }
            }

            node.end = true;
            return result == null ? s : result;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Trie trie = new Trie();
        Map<String, Integer> nameCount = new HashMap<>();
        StringBuilder sb = new StringBuilder();

        while (n-- > 0) {
            String name = br.readLine();
            int count = nameCount.getOrDefault(name, 1);

            if (count == 1) {
                String result = trie.insert(name);
                sb.append(result).append('\n');
            } else {
                String newName = name + count;
                trie.insert(newName);
                sb.append(newName).append('\n');
            }

            nameCount.put(name, count + 1);
        }

        System.out.print(sb);
    }
}
