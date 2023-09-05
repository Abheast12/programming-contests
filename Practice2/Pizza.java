import java.io.*;
import java.util.*;

public class Pizza {
    static class CompIntArr implements Comparator<int[]> {

        @Override
        public int compare(int[] o1, int[] o2) {
            return o1[0] - o2[0];
        }
        
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int nums = Integer.parseInt(br.readLine());
        int[] arr = new int[nums];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < nums; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < nums; i++) {
            arr[i] -= Integer.parseInt(st.nextToken());
        }
        br.close();

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