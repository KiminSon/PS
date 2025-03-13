import java.io.*;
import java.util.*;

public class Main {

    static class pt implements Comparable<pt> {
        int s, e, w, n;

        pt(int ss, int ee, int ww, int nn) {
            s = ss;
            e = ee;
            w = ww;
            n = nn;
        }

        @Override
        public int compareTo(pt o) {
            return Integer.compare(w, o.w);
        }
    }

    static int n, m, cnt;
    static PriorityQueue<pt> pmn = new PriorityQueue<>();
    static PriorityQueue<pt> pmx = new PriorityQueue<>();
    static PriorityQueue<pt> pmd = new PriorityQueue<>();
    static pt[] ptl;
    static boolean[] vmx, vmn, vmd;
    static int[] p, r;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        if (n > m) {
            sb.append("NO");
            System.out.print(sb);
            return;
        }
        sb.append("YES\n");
        ptl = new pt[m + 1];
        vmx = new boolean[m + 1];
        vmn = new boolean[m + 1];
        vmd = new boolean[m + 1];
        p = new int[n + 1];
        r = new int[n + 1];

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            pt p = new pt(s, e, w, i);
            pt px = new pt(s, e, -w, i);
            ptl[i] = p;
            pmn.add(p);
            pmx.add(px);
            pmd.add(p);
        }

        init();
        while (cnt < n - 1) {
            pt p = pmn.poll();
            if (unite(p.s, p.e)) {
                cnt++;
                vmn[p.n] = true;
            }
        }

        init();
        while (cnt < n - 1) {
            pt p = pmx.poll();
            if (unite(p.s, p.e)) {
                cnt++;
                vmx[p.n] = true;
            }
        }

        init();
        pt pmn = null, pmx = null, pm = null;
        for (int i = 1; i <= m; i++) {
            if (!vmx[i] && !vmn[i]) {
                pm = ptl[i];
                break;
            }
            if (!vmx[i]) {
                pmx = ptl[i];
            }
            if (!vmn[i]) {
                pmn = ptl[i];
            }
        }
        if (pm != null) {
            unite(pm.s, pm.e);
            vmd[pm.n] = true;
        } else {
            if (unite(pmx.s, pmx.e)) {
                vmd[pmx.n] = true;
            }
            if (unite(pmn.s, pmn.e)) {
                vmd[pmn.n] = true;
            }
        }
        while (!pmd.isEmpty()) {
            pt p = pmd.poll();
            if (unite(p.s, p.e)) {
                vmd[p.n] = true;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (vmd[i]) {
                sb.append(i).append(" ");
            }
        }
        System.out.print(sb);
    }

    static void init() {
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            r[i] = 1;
        }
    }

    static boolean unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (r[x] > r[y]) {
            p[y] = x;
            r[x] += r[y];
        } else {
            p[x] = y;
            r[y] += r[x];
        }
        return true;
    }

    static int find(int x) {
        if (x == p[x]) {
            return x;
        }
        return p[x] = find(p[x]);
    }
}
