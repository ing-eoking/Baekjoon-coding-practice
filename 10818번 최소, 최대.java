import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        st = new StringTokenizer(bf.readLine());
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for(int i = 0; i < N; i++){
            int v = Integer.parseInt(st.nextToken());
            if(min > v) min = v;
            if(max < v) max = v;
        }
        bw.write(Integer.toString(min) + " "+Integer.toString(max));
        bw.close();
    }
}
