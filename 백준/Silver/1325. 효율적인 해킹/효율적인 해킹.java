import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        List<Integer>[] arr = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
            arr[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[b].add(a);
        }

        int[] cntList = new int[n + 1];
        int[] visited = new int[n + 1];
        int max = 0;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            visited[i] = i;
            for (int first : arr[i]) {
                if (visited[first] == i)
                    continue;
                q.add(first);
                cnt++;
                visited[first] = i;
            }

            while (!q.isEmpty()) {
                int tmp = q.poll();
                for (int j : arr[tmp]) {
                    if (visited[j] == i)
                        continue;
                    if (arr[j].isEmpty()) {
                        visited[j] = i;
                        cnt++;
                    } else {
                        visited[j] = i;
                        q.add(j);
                        cnt++;
                    }
                }
            }
            cntList[i] = cnt;
            max = Math.max(max, cnt);
        }

        StringBuffer sb = new StringBuffer();
        for (int i = 1; i <= n; i++) {
            if (cntList[i] == max) {
                sb.append(i).append(" ");
            }
        }
        System.out.println(sb);
    }
}