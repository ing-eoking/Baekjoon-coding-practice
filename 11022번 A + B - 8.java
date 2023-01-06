import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine());
        for(int i =1; i <= T; i++){
            st = new StringTokenizer(bf.readLine());
            int [] arr = {Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
            bw.write("Case #"+Integer.toString(i)+": ");
            bw.write(Integer.toString(arr[0]) + " + " + Integer.toString(arr[1]));
            bw.write(" = "+Integer.toString(arr[0]+arr[1])+"\n");
        }
        bw.close();
    }
}
