import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        String sN = bf.readLine();
        int N = Integer.parseInt(sN);
        for(int i = 1; i <= 9; i++){
            bw.write(sN + " * " + Integer.toString(i) + " = " + Integer.toString(N*i));
            if(i != 9) bw.write("\n");
            bw.flush();
        }
        bw.close();
    }
}
