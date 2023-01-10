import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        int n = 1, cnt = 1;
        while(N > n){
            n += 6*cnt;
            cnt++;
        }
        bw.write(Integer.toString(cnt));
        bw.close();
    }
}
