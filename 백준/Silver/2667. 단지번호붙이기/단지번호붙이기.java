import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int[][] arr;
    static boolean[][] visited;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static class loc {
        int x;
        int y;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }

        List<Integer> lst = new ArrayList();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && arr[i][j] == 1) {
                    int cnt = 1;
                    loc l = new loc();
                    l.x = i;
                    l.y = j;
                    visited[i][j] = true;
                    Queue<loc> q = new LinkedList();
                    q.add(l);
                    while (!q.isEmpty()) {
                        loc cur = q.poll();
                        for (int k = 0; k < 4; k++) {
                            int nx = cur.x + dx[k];
                            int ny = cur.y + dy[k];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || arr[nx][ny] == 0) {
                                continue;
                            }
                            visited[nx][ny] = true;
                            cnt++;
                            loc tmp = new loc();
                            tmp.x = nx;
                            tmp.y = ny;
                            q.add(tmp);
                        }
                    }
                    lst.add(cnt);
                }
            }
        }
        Collections.sort(lst);

        int sz = lst.size();
        StringBuilder sb = new StringBuilder();
        sb.append(sz).append("\n");
        for (int i = 0; i < sz; i++) {
            sb.append(lst.get(i)).append("\n");
        }
        System.out.println(sb.toString());
    }
}