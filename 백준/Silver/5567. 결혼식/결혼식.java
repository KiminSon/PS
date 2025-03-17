import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {

	static boolean[] visited;
	static boolean[][] arr;
	static int n, m, cnt;

	public static void main(String[] args) throws Exception {
		// --------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		visited = new boolean[n + 1];
		arr = new boolean[n + 1][n + 1];
		for (int i = 0; i < m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a][b] = true;
			arr[b][a] = true;
		}
		visited[1] = true;
		Queue<Integer> q = new ArrayDeque<>();
		for (int i = 1; i <= n; i++) {
			if (arr[1][i] && !visited[i]) {
				cnt++;
				q.add(i);
				visited[i] = true;
			}
		}

		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int i = 1; i <= n; i++) {
				if (arr[cur][i] && !visited[i]) {
					cnt++;
					visited[i] = true;
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		sb.append(cnt);
		System.out.print(sb);
	}

}
