import java.io.*;
import java.util.*;

public class Rungs {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] rungs = new int[m][2];
        for (int i = 0; i < m; i++) {
            int next = Integer.parseInt(br.readLine());
            rungs[i][0] = next - 1;
            rungs[i][1] = next;
        }

        br.close();

        int[] permu = new int[n];
        for (int i = 0; i < n; i++) {
            int curr = i;
            for (int[] j : rungs) {
                if (curr == j[0]) {
                    curr = j[1];
                } else if (curr == j[1]) {
                    curr = j[0];
                }
            }
            permu[curr] = i + 1;
        }
        for (int i : permu) {
            pw.println(i);
        }
        pw.close();
    }
}