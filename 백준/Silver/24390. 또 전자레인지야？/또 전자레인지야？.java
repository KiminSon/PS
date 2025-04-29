import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int m = Integer.parseInt(String.valueOf(str.charAt(0))) * 10 + Integer.parseInt(String.valueOf(str.charAt(1)));
        int s = Integer.parseInt(String.valueOf(str.charAt(3))) * 10 + Integer.parseInt(String.valueOf(str.charAt(4)));
        int cnt = 1;
        cnt += m / 10 + m % 10;
        cnt += s / 30 + (s % 30) / 10;

        int allsec = m * 60 + s;
        if (allsec >= 30) {
            allsec -= 30;
        } else {
            System.out.print(cnt);
            return;
        }
        int mm = allsec / 60;
        int ss = allsec % 60;
        int ccnt = 1;
        ccnt += mm / 10 + mm % 10;
        ccnt += ss / 30 + (ss % 30) / 10;
        if (ccnt < cnt) {
            System.out.print(ccnt);
        } else {
            System.out.print(cnt);
        }
    }
}
