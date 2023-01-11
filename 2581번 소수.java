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
        return num;
    }
    public static void main(String[] args) throws IOException {
        int M =  Integer.parseInt(bf.readLine());
        int N = Integer.parseInt(bf.readLine());
        int sum = 0, min = 0;
        for(int i = M; i <= N; i++)
            if(min == 0) min = is(i);
            else sum += is(i);
        if(min + sum == 0) bw.write("-1");
        else bw.write(Integer.toString(sum+min) + "\n" + Integer.toString(min));
        bw.close();
    }
}
