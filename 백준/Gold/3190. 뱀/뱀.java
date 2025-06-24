import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    /*
     * 0은 공백
     * 1은 뱀
     * 2는 사과
     * 큐는 뱀의 좌표
     *
     * 0오
     * 1밑
     * 2왼
     * 3위
     * */

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Queue<int[]> q = new ArrayDeque<>();
        Queue<Integer> sq = new ArrayDeque<>();
        Queue<Character> mq = new ArrayDeque<>();
        int n, m, t = 0, x, y;
        n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n + 1][n + 1];
        m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            arr[x][y] = 2;
        }
        m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            char c = st.nextToken().charAt(0);
            sq.add(s);
            mq.add(c);
        }
        m = 0;
        x = 1;
        y = 1;
        q.add(new int[]{1, 1});
        arr[1][1] = 1;
        while (true) {
            if (m == 0) {
                y++;
            } else if (m == 1) {
                x++;
            } else if (m == 2) {
                y--;
            } else {
                x--;
            }
            t++;

            if (x <= 0 || x > n || y <= 0 || y > n || arr[x][y] == 1) {
                break;
            }

            if (arr[x][y] == 0) {
                int tx = q.peek()[0];
                int ty = q.poll()[1];
                arr[tx][ty] = 0;
            }

            arr[x][y] = 1;
            q.add(new int[]{x, y});

            if (!sq.isEmpty() && sq.peek() == t) {
                sq.poll();
                char tmp = mq.poll();
                if (tmp == 'L') {
                    m = (m + 3) % 4;
                } else {
                    m = (m + 1) % 4;
                }
            }
        }
        System.out.print(t);
    }
}
