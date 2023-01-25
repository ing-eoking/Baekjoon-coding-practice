import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine()), mmax = 0;
        st = new StringTokenizer(bf.readLine());
        int [] A = new int [N];
        int [] dp = new int [N];
        for(int i = 0; i < N; i++) A[i] = Integer.parseInt(st.nextToken());
        for(int i = 1; i < N; i++)
            for(int j = 0; j < i; j++)
                if(A[i] > A[j]){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    if(mmax < dp[i]) mmax = dp[i];
                }

        bw.write(Integer.toString(mmax+1));
        bw.close();
    }
}
