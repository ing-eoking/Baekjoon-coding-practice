import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine()), mmax = 0;
        int [][] A = new int [N][2];
        int [] dp1 = new int [N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(bf.readLine());
            A[i][0] = Integer.parseInt(st.nextToken());
            A[i][1] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(A,(o1, o2) ->{return o1[0]-o2[0];});
        for(int i = 1; i < N; i++)
            for(int j = 0; j < i; j++) {
                if (A[i][1] > A[j][1]) {
                    dp1[i] = Math.max(dp1[i], dp1[j] + 1);
                    if(dp1[i] > mmax) mmax = dp1[i];
                }
            }
        bw.write(Integer.toString(N-1-mmax)+" ");
        bw.close();
    }
}
