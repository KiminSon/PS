import java.io.*;
import java.util.*;

public class Main {

    static int[][] d = {
            {9, 3, 1},
            {9, 1, 3},
            {1, 3, 9},
            {3, 1, 9},
            {3, 9, 1},
            {1, 9, 3}
    };

    static int n;
    static int[] arr = new int[3];
    static int[][][] visited = new int[61][61][61];

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Queue<int[]> q = new ArrayDeque<>();
        visited[arr[0]][arr[1]][arr[2]] = 1;
        q.add(new int[]{arr[0], arr[1], arr[2]});
        while (!q.isEmpty()) {
            if (visited[0][0][0]-- > 0) {
                StringBuilder sb = new StringBuilder();
                sb.append(visited[0][0][0]);
                System.out.print(sb);
                return;
            }
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int z = cur[2];
            for (int i = 0; i < 6; i++) {
                int nx = Math.max(0, x - d[i][0]);
                int ny = Math.max(0, y - d[i][1]);
                int nz = Math.max(0, z - d[i][2]);
                if (visited[nx][ny][nz] > 0) {
                    continue;
                }
                visited[nx][ny][nz] = visited[x][y][z] + 1;
                q.add(new int[]{nx, ny, nz});
            }
        }
    }
}
