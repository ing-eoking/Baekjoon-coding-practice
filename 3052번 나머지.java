import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        boolean [] tf = new boolean[42];
        int n = 0;
        for(int i = 0; i < 10; i++){
            int v = Integer.parseInt(bf.readLine())%42;
            if(!tf[v]) n++;
            tf[v] = true;
        }
        bw.write(Integer.toString(n));
        bw.close();
    }
}
