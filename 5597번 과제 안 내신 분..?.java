import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int value = 1073741823;
        for(int i = 1; i <= 28; i++){
            int v = Integer.parseInt(bf.readLine());
            value = value & ~(1 << (v-1));
        }
        int big = (int)(Math.log(value)/Math.log(2));
        int small = (int)(Math.log(value & ~(1 << big))/Math.log(2));
        bw.write (Integer.toString(small+1)+"\n");
        bw.write(Integer.toString(big+1));
        bw.close();
    }
}
