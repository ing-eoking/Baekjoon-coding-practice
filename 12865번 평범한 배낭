import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int [][] obj = new int[N][2];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(bf.readLine());
            obj[i][0] = Integer.parseInt(st.nextToken());
            obj[i][1] = Integer.parseInt(st.nextToken());
        }

        int [][] DP = new int[N+1][K+1];
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= K; j++){
                if(j-obj[i-1][0] >= 0) DP[i][j] = Math.max(DP[i-1][j],DP[i-1][j-obj[i-1][0]]+obj[i-1][1]);
                else DP[i][j] = DP[i-1][j];
            }
        }
        bw.write(Integer.toString(DP[N][K]));
        bw.flush();
        bw.close();
    }
}
