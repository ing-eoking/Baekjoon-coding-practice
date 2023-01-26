import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long [] a = new long [N+1];
        long [] NM = new long [M];
        st = new StringTokenizer(bf.readLine());
        for(int i = 1; i <= N; i++){
            a[i] = Integer.parseInt(st.nextToken()) + a[i-1];
            NM[(int)(a[i] % M)]++;
        }
        long sum = 0;
        for(int i = 0; i < M; i++) sum += NM[i]*(NM[i]-1)/2;
        bw.write(Long.toString(sum + NM[0]));
        bw.close();
    }
}
