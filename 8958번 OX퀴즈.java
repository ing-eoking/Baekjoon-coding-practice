import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(bf.readLine(), "X");
            int sum = 0;
            while(st.hasMoreTokens()){
                int n = st.nextToken().length();
                sum += n*(n+1)/2;
            }
            bw.write(Integer.toString(sum)+"\n");
        }
        bw.close();
    }
}
