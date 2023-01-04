import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static Long [][][]dp = new Long[51][102][2];
    static int N = 0;
    static Long K;
    public static Long cal(int i, int j, int is){
        if(i == N) return Long.valueOf((is != 0) | (j != 0)? 1:0);
        if(dp[i][j+N][is] != null) return dp[i][j+N][is];
        return (dp[i][j+N][is] = cal(i+1, j+1, is) + cal(i+1, j-1, (is != 0) || (j <= 0)? 1:0));
    }
    public static void track(int i, int j, int is, Long k) throws IOException {
        if(i==N) return;
        if(dp[i+1][j+1+N][is] == null || dp[i+1][j+1+N][is]>=k){
            if((i == N-1) && (k == 2)) bw.write(")");
            else bw.write("(");
            track(i+1, j +1, is, k);
        }
        else{
            bw.write(")");
            track(i+1, j-1, (is != 0) || (j <= 0)? 1:0, k - dp[i+1][j+1+N][is]);
        }
    }
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());
        cal(0,0,0);
        if(dp[0][N][0] != null && K+1>dp[0][N][0]) bw.write("-1");
        else track(0,0,0,K+1);
        bw.flush();
        bw.close();
    }
}
