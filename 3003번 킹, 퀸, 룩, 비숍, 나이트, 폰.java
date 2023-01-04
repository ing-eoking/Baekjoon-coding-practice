import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int[] arr = {1,1,2,2,2,8};
        int i = 0;
        while(st.hasMoreTokens()){
            bw.write(Integer.toString(arr[i]-Integer.parseInt(st.nextToken())));
            if(arr.length -1 > i) bw.write(" ");
            i = i+ 1;
        }
        bw.flush();
        bw.close();
    }
}
