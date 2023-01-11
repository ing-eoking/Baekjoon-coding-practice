import java.io.*;
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
        int T = Integer.parseInt(bf.readLine());
        while(T-- > 0){
            int n = Integer.parseInt(bf.readLine());
            for(int i = n/2; i >= 2; i--)
                if(is(i) + is(n-i) == 2){
                    bw.write(Integer.toString(i)+" " + Integer.toString(n-i)+"\n");
                    break;
                }
        }

        bw.close();
    }
}
