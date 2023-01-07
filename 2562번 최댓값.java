import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int max = Integer.MIN_VALUE, imax = 0;
        for(int i = 0; i < 9; i++){
            int v = Integer.parseInt(bf.readLine());
            if(max < v) {
                max = v;
                imax = i+1;
            }
        }
        bw.write(Integer.toString(max) + "\n"+Integer.toString(imax));
        bw.close();
    }
}
