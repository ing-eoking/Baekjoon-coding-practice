import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        int fiv = N/5, thr = (N%5)/3;
        while(fiv>=0)
            if(fiv*5 + thr*3 == N) break;
            else{
                fiv--;
                thr = (N-fiv*5)/3;
            }
        if(fiv < 0) thr = 0;
        bw.write(Integer.toString(fiv+thr));
        bw.flush();
        bw.close();
    }
}
