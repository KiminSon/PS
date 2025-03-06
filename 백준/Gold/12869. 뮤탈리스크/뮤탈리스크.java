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
    static boolean[][][] visited = new boolean[61][61][61];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Queue<int[]> q = new ArrayDeque<>();
        visited[arr[0]][arr[1]][arr[2]] = true;
        q.add(new int[]{arr[0], arr[1], arr[2], 1});
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int z = cur[2];
            int cnt = cur[3];
            for (int i = 0; i < 6; i++) {
                int nx = x - d[i][0] < 0 ? 0 : x - d[i][0];
                int ny = y - d[i][1] < 0 ? 0 : y - d[i][1];
                int nz = z - d[i][2] < 0 ? 0 : z - d[i][2];

                if (visited[nx][ny][nz]) {
                    continue;
                }
                visited[nx][ny][nz] = true;
                if (nz == 0 && ny == 0 && nx == 0) {
                    System.out.println(cnt);
                    return;
                }
                q.add(new int[]{nx, ny, nz, cnt + 1});
            }
        }
    }
}
