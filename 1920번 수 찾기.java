import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        st = new StringTokenizer(bf.readLine());
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < N; i++) set.add(Integer.parseInt(st.nextToken()));
        int M = Integer.parseInt(bf.readLine());
        st = new StringTokenizer(bf.readLine());
        while(M-- > 0)
            bw.write(set.contains(Integer.parseInt(st.nextToken()))?"1\n":"0\n");
        bw.close();
    }
}
