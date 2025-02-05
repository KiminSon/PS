import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException, Exception {
//        System.setIn(new FileInputStream("Test5.txt"));
        // ---------여기에 코드를 작성하세요.---------------//
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = 19;
        int[][] arr = new int[n][n];

        int[] dx = { 0, 0, 1, -1, -1, -1, 1, 1 };
        int[] dy = { 1, -1, 0, 0, -1, 1, 1, -1 };

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (arr[i][j] == 1 || arr[i][j] == 2) {
                    for (int k = 0; k < 8; k++) {
                        int cnt = 1;
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        while (true) {
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                                if (cnt == 5) {
                                    int lx = i - dx[k];
                                    int ly = j - dy[k];
                                    if (lx < 0 || lx >= n || ly < 0 || ly >= n) {
                                        sb.append(arr[i][j]).append("\n").append(i + 1).append(" ").append(j + 1);
                                        System.out.println(sb.toString());
                                        return;
                                    }
                                    if (arr[lx][ly] == arr[i][j]) {
                                        break;
                                    }
                                    sb.append(arr[i][j]).append("\n").append(i + 1).append(" ").append(j + 1);
                                    System.out.println(sb.toString());
                                    return;
                                }
                                break;
                            }
                            if (cnt == 5 && arr[i][j] == arr[nx][ny]) {
                                break;
                            }
                            if (cnt == 5 && arr[i][j] != arr[nx][ny]) {
                                int lx = i - dx[k];
                                int ly = j - dy[k];
                                if (lx < 0 || lx >= n || ly < 0 || ly >= n) {
                                    sb.append(arr[i][j]).append("\n").append(i + 1).append(" ").append(j + 1);
                                    System.out.println(sb.toString());
                                    return;
                                }
                                if (arr[lx][ly] == arr[i][j]) {
                                    break;
                                }
                                sb.append(arr[i][j]).append("\n").append(i + 1).append(" ").append(j + 1);
                                System.out.println(sb.toString());
                                return;
                            }
                            if (arr[i][j] == arr[nx][ny]) {
                                cnt++;
                                nx += dx[k];
                                ny += dy[k];
                                continue;
                            }
                            if (arr[i][j] != arr[nx][ny]) {
                                break;
                            }
                            nx += dx[k];
                            ny += dy[k];
                        }
                    }
                }
            }
        }

        sb.append(0);
        System.out.println(sb.toString());
    }

}