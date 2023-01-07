import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        double sum = 0, max = 0;
        st = new StringTokenizer(bf.readLine());
        for(int i = 0; i < N; i++){
            double v = Double.parseDouble(st.nextToken());
            sum += v;
            if(v > max) max = v;
        }
        bw.write(Double.toString(sum*100/(max*N)));
        bw.close();
    }
}
