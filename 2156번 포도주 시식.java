import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        int [] A = new int [N];
        for(int i = 0; i < N; i++) A[i] = Integer.parseInt(bf.readLine());
        int [] dp = new int [N];
        dp[0] = A[0];
        if(N > 1)dp[1] = A[0]+A[1];
        if(N > 2)dp[2] = Math.max(Math.max(A[0]+A[1], A[0] + A[2]),A[1]+A[2]);
        for(int i = 3; i < N; i++){
            dp[i] = dp[i-3] + A[i-1] + A[i];
            dp[i] = Math.max(dp[i-2]+A[i], dp[i]);
            dp[i] = Math.max(dp[i-1], dp[i]);
        }
        bw.write(Integer.toString(dp[N-1]));
        bw.close();
    }
}
