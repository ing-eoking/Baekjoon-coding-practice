import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
        int [][] dp = new int [N+1][K+1];
        for(int i = 0; i <= N; i++)
            for(int j = 0; j <= K; j++)
                if(j > i) break;
                else if(j == 0 || j == N) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        bw.write(Integer.toString(dp[N][K]));
        bw.close();
    }
}
