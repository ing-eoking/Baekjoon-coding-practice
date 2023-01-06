import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        double R = Double.parseDouble(bf.readLine());
        bw.write(Double.toString(R*R*Math.PI)+"\n");
        bw.write(Double.toString(R*R*2));
        bw.flush();
        bw.close();
    }
}
