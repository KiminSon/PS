import java.util.*;
import java.io.*;

public class Main {

    static int k, w, h;
    static int[][] arr;
    static int[][][] cost;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static int[] hx = {1, 1, -1, -1, 2, 2, -2, -2};
    static int[] hy = {2, -2, 2, -2, 1, -1, 1, -1};

    static class Cell implements Comparable<Cell> {
        int x;
        int y;
        int d;
        int c;

        public Cell(int x, int y, int d, int c) {
            this.x = x;
            this.y = y;
            this.d = d;
            this.c = c;
        }

        public Cell() {

        }

        @Override
        public int compareTo(Cell o) {
            return Integer.compare(this.c, o.c);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        arr = new int[h][w];
        cost = new int[h][w][k + 1];
        for (int i = 0; i < h; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < w; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                Arrays.fill(cost[i][j], Integer.MAX_VALUE);
            }
        }

        PriorityQueue<Cell> q = new PriorityQueue<>();
        cost[0][0][0] = 0;
        q.offer(new Cell(0, 0, 0, cost[0][0][0]));
        while (!q.isEmpty()) {
            Cell cur = q.poll();
            int x = cur.x;
            int y = cur.y;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || arr[nx][ny] == 1) {
                    continue;
                }
                if (cost[nx][ny][cur.d] > cost[x][y][cur.d] + 1) {
                    cost[nx][ny][cur.d] = cost[x][y][cur.d] + 1;
                    q.offer(new Cell(nx, ny, cur.d, cost[nx][ny][cur.d]));
                }
            }
            for (int i = 0; i < 8; i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || arr[nx][ny] == 1 || cur.d + 1 > k) {
                    continue;
                }
                if (cost[nx][ny][cur.d + 1] > cost[x][y][cur.d] + 1) {
                    cost[nx][ny][cur.d + 1] = cost[x][y][cur.d] + 1;
                    q.offer(new Cell(nx, ny, cur.d + 1, cost[nx][ny][cur.d + 1]));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        int mn = Integer.MAX_VALUE;
        for (int i = 0; i <= k; i++) {
            mn = Math.min(mn, cost[h - 1][w - 1][i]);
        }
        if (mn == Integer.MAX_VALUE) {
            mn = -1;
        }
        sb.append(mn);
        System.out.print(mn);
    }
}