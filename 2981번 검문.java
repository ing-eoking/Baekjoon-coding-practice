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
        int M = Integer.parseInt(bf.readLine()), B;
        int A = Integer.parseInt(bf.readLine());
        int [] arr = new int [M-1];
        for(int i = 0; i < M-1; i++){
            B = Integer.parseInt(bf.readLine());
            arr[i] = Math.abs(A-B);
            A= B;
        }
        int GCD = arr[0];
        for(int i = 0; i < M-1; i++){
            GCD = gcd(arr[i], GCD);
        }
        for(int i = 2; i <= GCD; i++)
            if(GCD % i == 0) bw.write(Integer.toString(i)+" ");
        bw.close();

    }
}
