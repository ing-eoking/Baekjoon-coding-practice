import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(bf.readLine());
        st = new StringTokenizer(bf.readLine());
        int [] arr = new int [201];
        for(int i = 0; i < n; i++){
            arr[Integer.parseInt(st.nextToken())+100]++;
        }
        int v = Integer.parseInt(bf.readLine());
        bw.write(Integer.toString(arr[v+100]));
        bw.close();
    }
}
