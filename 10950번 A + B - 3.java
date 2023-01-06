import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine());
        for(int i = 0; i < T; i++){
            st = new StringTokenizer(bf.readLine());
            bw.write(Integer.toString(Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken()))+"\n");
            bw.flush();
        }
        bw.close();
    }
}
