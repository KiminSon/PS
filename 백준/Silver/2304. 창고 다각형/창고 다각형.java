import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] height = new int[1001];

        int left = 1001, right = 0, maxH = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            height[l] = h;

            if (h > maxH) {
                maxH = h;
                maxIdx = l;
            }

            left = Math.min(left, l);
            right = Math.max(right, l);
        }

        int area = 0;
        int h = 0;
        for (int i = left; i < maxIdx; i++) {
            h = Math.max(h, height[i]);
            area += h;
        }

        h = 0;
        for (int i = right; i > maxIdx; i--) {
            h = Math.max(h, height[i]);
            area += h;
        }

        area += maxH;

        System.out.println(area);
    }
}
