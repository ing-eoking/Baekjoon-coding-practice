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
        int n = -1;
        while((n = Integer.parseInt(bf.readLine())) != 0){
            int sum = 0;
            for(int i = n +1; i <= 2*n; i++)
                sum += is(i);
            bw.write(Integer.toString(sum)+ "\n");
        }
        bw.close();
    }
}
