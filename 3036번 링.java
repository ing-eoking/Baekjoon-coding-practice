import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static int gcd(int a, int b){
        if (b == 0) return a;
        else return gcd(b, a % b);
    }
    public static void main(String[] args) throws IOException {
        int N  = Integer.parseInt(bf.readLine()), n, cur;
        st = new StringTokenizer(bf.readLine());
        int first = Integer.parseInt(st.nextToken());
        while(N-- > 1){
            cur = Integer.parseInt(st.nextToken());
            n = gcd(first, cur);
            bw.write(Integer.toString(first/n)+"/"+Integer.toString(cur/n)+"\n");
        }
        bw.close();
    }
}
