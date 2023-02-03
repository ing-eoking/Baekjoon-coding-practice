import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), sum = 0, midx = 0;
        int [] memory = new int [N+1], cost = new int [N+1];
        st = new StringTokenizer(bf.readLine());
        for(int i = 1; i <= N; i++) memory[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(bf.readLine());
        for(int i = 1; i <= N; i++) sum += cost[i] = Integer.parseInt(st.nextToken());
        int [][] dp = new int[N+1][sum+1];
        for(int i = 1; i <= N; i++)
            for(int j = 0; j <= sum; j++) {
                if (j >= cost[i]) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
            }
        while(dp[N][midx] < M) midx++;
        bw.write(Integer.toString(midx));
        bw.close();
    }
}
