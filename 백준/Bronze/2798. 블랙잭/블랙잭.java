import java.util.*;
import java.io.*;

public class Main {

	static int n, m, ans;
	static int[] arr;

	public static void main(String[] args) throws Exception {
		// --------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		f(0, 0, 0);

		StringBuilder sb = new StringBuilder();
		sb.append(ans);
		System.out.print(sb);
	}

	static void f(int d, int nxt, int c) {
		if (c > m) {
			return;
		}
		if (d == 3) {
			ans = Math.max(ans, c);
			return;
		}
		for (int i = nxt; i < n; i++) {
			f(d + 1, i + 1, c + arr[i]);
		}
	}

}
