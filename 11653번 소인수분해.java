import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void is(int num) throws IOException {
        if(num < 2) return;
        int i = 1;
        while((num %(++i)) != 0){}
        bw.write(Integer.toString(i)+"\n");
        is(num/(i));
    }
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        is(N);
        bw.close();
    }
}
