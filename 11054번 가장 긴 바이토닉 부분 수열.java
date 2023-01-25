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
        int [] dp1 = new int [N];
        int [] dp2 = new int [N];
        for(int i = 0; i < N; i++) A[i] = Integer.parseInt(st.nextToken());
        for(int i = 1; i < N; i++)
            for(int j = 0; j < i; j++) {
                if (A[i] > A[j]) dp1[i] = Math.max(dp1[i], dp1[j] + 1);
                if (A[N-1-i] > A[N-1-j])
                    dp2[N - 1 - i] = Math.max(dp2[N - 1 - i], dp2[N - 1 - j] + 1);
            }
        for(int i = 0; i < N; i++) if(mmax < dp1[i] + dp2[i]) mmax = dp1[i] + dp2[i];
        bw.write(Integer.toString(mmax+1));
        bw.close();
    }
}
