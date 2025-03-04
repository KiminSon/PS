import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static int n, ans = 1, mn = Integer.MAX_VALUE, mx = Integer.MIN_VALUE;
	static int[][] arr;
	static boolean[][] visited;
	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				mn = Math.min(mn, arr[i][j]);
				mx = Math.max(mx, arr[i][j]);
			}
		}

		for (int fl = mn; fl < mx; fl++) {
			visited = new boolean[n][n];
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (!visited[i][j] && arr[i][j] > fl) {
						cnt++;
						visited[i][j] = true;
						Queue<Point> q = new ArrayDeque<>();
						q.add(new Point(i, j));
						while (!q.isEmpty()) {
							Point p = q.poll();
							for (int k = 0; k < 4; k++) {
								int nx = p.x + dx[k];
								int ny = p.y + dy[k];
								if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
									continue;
								}
								if (visited[nx][ny] || arr[nx][ny] <= fl) {
									continue;
								}
								visited[nx][ny] = true;
								q.add(new Point(nx, ny));
							}
						}
					}
				}
			}
			ans = Math.max(ans, cnt);
		}

		StringBuilder sb = new StringBuilder();
		sb.append(ans);
		System.out.print(sb);
	}

}
