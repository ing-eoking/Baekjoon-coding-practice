import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int X = Integer.parseInt(bf.readLine());
        int N = Integer.parseInt(bf.readLine());
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(bf.readLine());
            X = X - Integer.parseInt(st.nextToken())*Integer.parseInt(st.nextToken());
        }
        bw.write(X==0?"Yes":"No");
        bw.close();
    }
}
