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
        st = new StringTokenizer(bf.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int GCD = gcd(A,B);
        bw.write(Integer.toString(GCD)+"\n");
        bw.write(Integer.toString(A*B/GCD));
        bw.close();

    }
}
