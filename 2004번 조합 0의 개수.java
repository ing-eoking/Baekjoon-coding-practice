import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static long fac(long num, long vid){
        long c = 0;
        do{ c += num;}while((num /= vid)> 0);
        return c;
    }
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        long N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        long fiv = fac(N, 5) - fac(M, 5) - fac(N-M,5);
        long two = fac(N, 2) - fac(M, 2) - fac(N-M,2);
        bw.write(Long.toString(Math.min(fiv, two)));
        bw.close();

    }
}
