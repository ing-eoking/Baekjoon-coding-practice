import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine()) - 1;
        int i = 0;
        for(; ; i++) if(N < i*(i+1)/2) break;
        int x = N - i*(i-1)/2 + 1;
        int y = i+ 1 - x;
        if(i% 2 == 0)bw.write(Integer.toString(x)+"/"+Integer.toString(y));
        else bw.write(Integer.toString(y)+"/"+Integer.toString(x));
        bw.close();
    }
}
