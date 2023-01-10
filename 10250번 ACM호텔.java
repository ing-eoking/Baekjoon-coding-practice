import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine());
        for(int t = 0; t < T; t++){
            st = new StringTokenizer(bf.readLine());
            int [] arr = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
            arr[2]--;
            int front = arr[2] / arr[0] + 1;
            int back = arr[2] % arr[0] + 1;
            bw.write(Integer.toString(back*100 + front)+"\n");
        }
        bw.flush();
        bw.close();
    }
}
