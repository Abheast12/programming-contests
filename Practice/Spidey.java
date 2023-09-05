import java.io.*;
import java.util.*;

public class Spidey {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        long t = Integer.parseInt(st.nextToken());
        long s = Integer.parseInt(st.nextToken());
        br.close();

        long tAll = 2*t*t + 2*t + 1;
        long sAll = 0;
        for (int i = 0; i <= s * 2 / 3; i++) {
            sAll += s - i - (1 + i) / 2 + 1;
        }
        sAll *= 8;
        sAll -= 4 * (s + 2 + s * 2 / 3) - 1;
        
        //if (tAll > sAll) {
        //    System.out.println(1);
        //    return;
        //}
        for (int i = 2; i * i < tAll; i++) {
            if (tAll % i == 0 && sAll % i == 0) {
                tAll /= i;
                sAll /= i;
                i--;
            }
        }
        pw.println(tAll + "/" + sAll);
        pw.close();
    }
}