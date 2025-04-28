import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 현재 랭킹 수
        int t = Integer.parseInt(st.nextToken()); // 새 점수
        int p = Integer.parseInt(st.nextToken()); // 최대 랭킹 수

        int[] arr = new int[n];
        if (n != 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
        }

        // n==0이면 무조건 1등
        if (n == 0) {
            System.out.println(1);
            return;
        }

        int r = 1;
        int cur = -1; // t가 삽입될 위치

        for (int i = 0; i < n; i++) {
            if (t > arr[i]) {
                cur = i;
                break;
            } else if (t == arr[i]) {
                cur = i;
                break;
            } else {
                r++;
            }
        }

        if (cur == -1) {
            // 끝까지 왔는데 삽입 안 됨 (맨 마지막에 추가해야 함)
            if (n < p) {
                System.out.print(r);
            } else {
                System.out.print(-1);
            }
        } else {
            // 중간에 삽입
            if (n == p && arr[p - 1] >= t) {
                // 꽉 찼고, 새 점수가 마지막보다 작거나 같으면 못 들어감
                System.out.print(-1);
            } else {
                System.out.print(r);
            }
        }
    }
}
