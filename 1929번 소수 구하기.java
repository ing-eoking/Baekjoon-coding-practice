import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void is(int num) throws IOException {
        int i = 2;
        if(num == 1) return;
        while(num >= i*i) if(num % (i++) == 0) return;
        bw.write(Integer.toString(num)+"\n");
    }
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        for(int i = M; i <= N; i++) is(i);
        bw.close();
    }
}
