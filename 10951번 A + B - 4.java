import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        String str;
        while((str = bf.readLine())!=null){
            st = new StringTokenizer(str);
            int sum = Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken());
            bw.write(Integer.toString(sum)+"\n");
        }
        bw.close();
    }
}
