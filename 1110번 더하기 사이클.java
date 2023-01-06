import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        int n = N, i = 1;
        for(; ; i++){
            n = (n*10 + (n/10 + n)%10)%100;
            if(n == N) {
                bw.write(Integer.toString(i));
                break;
            }
        }
        bw.close();
    }
}
