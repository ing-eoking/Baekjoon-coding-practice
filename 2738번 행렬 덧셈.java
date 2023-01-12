import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int [][]arr = new int[N][M];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(bf.readLine());
            for(int j = 0; j < M; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(bf.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] += Integer.parseInt(st.nextToken());
                bw.write(Integer.toString(arr[i][j]));
                if (j != M - 1) bw.write(" ");
            }
            bw.write("\n");
        }

        bw.close();
    }
}
