import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int nf1 = 0, nf2 = 0;
    public static int fib(int n){
        if(n == 1 || n == 2) {nf1++; return 1;}
        else return fib(n-1)+fib(n-2);
    }
    public static void fibonacci(int n){
        int [] f = new int[n];
        f[0] = f[1] = 1;
        for(int i = 2; i < n; i++){
            f[i] = f[i-1] + f[i-2];
            nf2++;
        }
    }
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(bf.readLine());
        fib(n);
        fibonacci(n);
        bw.write(Integer.toString(nf1) + " " + Integer.toString(nf2));
        bw.close();
    }
}
