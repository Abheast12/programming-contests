import java.io.*;
import java.util.*;

public class Class {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        char[] c1 = br.readLine().toCharArray();
        char[] c2 = br.readLine().toCharArray();
        char[] merge = new char[c1.length + c2.length];
        for (int i = 0; i < c1.length; i++) {
            merge[i] = c1[i];
        }
        for (int i = c1.length; i < merge.length; i++) {
            merge[i] = c2[i - c1.length];
        }
        Arrays.sort(merge);
        String s = String.valueOf(merge);
        pw.println(s);

        br.close();
        pw.close();
    }
}