import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken()), mmax = -99999999;
        int [] A = new int [N+1];
        st = new StringTokenizer(bf.readLine());
        for(int i = 1; i <= N; i++) {
            A[i] = A[i - 1] + Integer.parseInt(st.nextToken());
            if(i >= M && mmax < A[i] - A[i-M]) mmax = A[i] - A[i-M];
        }
        bw.write(Integer.toString(mmax));
        bw.close();
    }
}
