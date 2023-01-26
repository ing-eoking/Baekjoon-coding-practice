import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken()), D1;
        int M = Integer.parseInt(st.nextToken()), D2;
        int [] A = new int [N+1];
        st = new StringTokenizer(bf.readLine());
        for(int i = 1; i <= N; i++)
            A[i] = A[i-1] + Integer.parseInt(st.nextToken());
        while(M-- > 0){
            st = new StringTokenizer(bf.readLine());
            D1 = Integer.parseInt(st.nextToken());
            D2 = Integer.parseInt(st.nextToken());
            bw.write(Integer.toString(A[D2] - A[D1-1])+'\n');
        }
        bw.close();
    }
}
