import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine()), n,m;
        int [][] dp = new int [30][30];
        for(int i = 0; i < 30; i++)
            for(int j = 0; j < 30; j++)
                if(j > i) break;
                else if(j == 0 || j == i) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

        while(T-- > 0){
            st = new StringTokenizer(bf.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            bw.write(Integer.toString(dp[m][n])+"\n");
        }
        bw.close();
    }
}
