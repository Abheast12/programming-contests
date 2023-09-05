import java.io.*;
import java.util.*;

public class E {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        br.close();

        HashSet<Integer>[] hs = new HashSet[m];
        for (int i = 0; i < hs.length; i++) {
            hs[i] = new HashSet<>();
        }
        for (int i = 0; i < args.length; i++) {
            
        }
        PriorityQueue<int[]> negatives = new PriorityQueue<>(new CompIntArr());
        PriorityQueue<int[]> positives = new PriorityQueue<>(new CompIntArr());
        for (int i = 0; i < arr.length; i++) {
            int val = arr[i];
            if (val < 0) {
                negatives.add(new int[] {-val, i+1});
            } else if (val > 0) {
                positives.add(new int[] {val, i+1});
            }
        }

        while (!(negatives.isEmpty() && positives.isEmpty())) {
            while (negatives.peek()[0] == 0) {
                negatives.poll();
            }
            while (positives.peek()[0] == 0) {
                positives.poll();
            }
            pw.print(positives.peek()[1]+" "+negatives.peek()[1]+" ");
            int min = Math.min(negatives.peek()[0], positives.peek()[0]);
            pw.println(min);
            negatives.peek()[0] -= min;
            positives.peek()[0] -= min;
            while (negatives.size() > 0 && negatives.peek()[0] == 0) {
                negatives.poll();
            }
            while (positives.size() > 0 && positives.peek()[0] == 0) {
                positives.poll();
            }
        }
        pw.close();
    }
}