import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(bf.readLine());
            int n = Integer.parseInt(st.nextToken());
            double [] arr = new double [n];
            double sum = 0;
            for(int j = 0; j < n; j++) {
                arr[j] = Double.parseDouble(st.nextToken());
                sum += arr[j];
            }
            double v = 0;
            for(int j = 0; j < n; j++)
                if(arr[j] > (sum/n))  v += 1;
            bw.write(String.format("%.3f",v*100/n)+"%\n");
        }
        bw.close();
    }
}
