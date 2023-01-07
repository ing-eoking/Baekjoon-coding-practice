import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(bf.readLine());
        for(int i = 0; i < N; i++){
            int v = Integer.parseInt(st.nextToken());
            if(X > v){
                bw.write(Integer.toString(v)+" ");
            }
        }
        bw.close();
    }
}
