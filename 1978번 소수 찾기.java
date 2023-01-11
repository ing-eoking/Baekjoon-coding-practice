import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static int is(int num){
        int i = 2;
        if(num == 1) return 0;
        while(num >= i*i) if(num % (i++) == 0) return 0;
        return 1;
    }
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine()), sum = 0;
        st = new StringTokenizer(bf.readLine());
        for(int i = 0; i < N; i++)
            sum += is(Integer.parseInt(st.nextToken()));
        bw.write(Integer.toString(sum));
        bw.close();
    }
}
