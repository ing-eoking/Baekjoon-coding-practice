import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine());
        for(int t = 0; t < T; t++){
            int k = Integer.parseInt(bf.readLine());
            int n = Integer.parseInt(bf.readLine());
            int [][] arr = new int [k+1][n+1];
            for(int i  = 1; i <= n; i++) arr[0][i] = i;
            for(int i = 1; i <= k; i++)
                for(int j = 1; j <= n; j++) arr[i][j] = arr[i-1][j] + arr[i][j-1];
            bw.write(Integer.toString(arr[k][n])+"\n");
        }
        bw.flush();
        bw.close();
    }
}
