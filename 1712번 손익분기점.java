import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int [] N = {Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
        int n = N[2] - N[1];
        n = n > 0 ? N[0]/n + 1 : -1;
        n = n > 0 ? n : -1;
        bw.write(Integer.toString(n));
        bw.close();
    }
}
