import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        byte[][] d = {
                {9, 3, 1},
                {9, 1, 3},
                {1, 3, 9},
                {3, 1, 9},
                {3, 9, 1},
                {1, 9, 3}
        };
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        byte n = Byte.parseByte(br.readLine());
        byte[] arr = new byte[3];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (byte i = 0; i < n; i++) {
            arr[i] = Byte.parseByte(st.nextToken());
        }
        boolean[][][] visited = new boolean[arr[0] + 1][arr[1] + 1][arr[2] + 1];
        Queue<byte[]> q = new ArrayDeque<>();
        visited[arr[0]][arr[1]][arr[2]] = true;
        q.add(new byte[]{arr[0], arr[1], arr[2], 1});
        while (!q.isEmpty()) {
            byte[] cur = q.poll();
            for (byte i = 0; i < 6; i++) {
                byte nx = cur[0] - d[i][0] < 0 ? 0 : (byte) (cur[0] - d[i][0]);
                byte ny = cur[1] - d[i][1] < 0 ? 0 : (byte) (cur[1] - d[i][1]);
                byte nz = cur[2] - d[i][2] < 0 ? 0 : (byte) (cur[2] - d[i][2]);

                if (visited[nx][ny][nz]) {
                    continue;
                }
                visited[nx][ny][nz] = true;
                if (nx == 0 && ny == 0 && nz == 0) {
                    System.out.println(cur[3]);
                    return;
                }
                q.add(new byte[]{nx, ny, nz, (byte) (cur[3] + 1)});
            }
        }
    }
}
