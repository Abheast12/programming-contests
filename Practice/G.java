import java.io.*;
import java.util.*;

public class G {
    public static long dfs(HashSet<Integer> nodes) {
        long ans = 1;
        for (Integer integer : nodes) {
            for (Integer child : reverse[integer]) {
                if (nodes.contains(child)) {
                    continue;
                }
                HashSet<Integer> temp = new HashSet<>();
                temp.add(child);
                ans *= dfs(temp);
                ans %= MOD;
            }
        }
        ans++;
        ans %= MOD;
        return ans;
    }

    public static ArrayList<Integer>[] reverse;
    public static final int MOD = 1000000007;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        int[] graph = new int[n];
        reverse = new ArrayList[n];
        for (int i = 0; i < reverse.length; i++) {
            reverse[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            int next = Integer.parseInt(br.readLine())-1;
            graph[i] = next;
            reverse[next].add(i);
        }
        br.close();

        boolean[] vis = new boolean[n];
        ArrayList<HashSet<Integer>> cycles = new ArrayList<>();
        outer: for (int i = 0; i < vis.length; i++) {
            if (!vis[i]) {
                HashMap<Integer, Integer> hm = new HashMap<>();
                ArrayList<Integer> list = new ArrayList<>();
                int curr = i;
                int index = 0;
                while (!hm.containsKey(curr)) {
                    if (vis[curr]) {
                        continue outer;
                    }
                    hm.put(curr, index);
                    index++;
                    list.add(curr);
                    vis[curr] = true;
                    curr = graph[curr];
                }
                HashSet<Integer> ans = new HashSet<>();
                for (int j = list.size() - 1; j >= hm.get(curr); j--) {
                    ans.add(list.get(j));
                }
                cycles.add(ans);
            }
        }

        long ans = 1;
        for (HashSet<Integer> arrayList : cycles) {
            ans *= dfs(arrayList);
            ans %= MOD;
        }
        ans--;
        ans %= MOD;
        pw.println(ans);
        pw.close();
    }
}