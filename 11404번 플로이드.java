import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static HashMap<Point, Long> hash = new HashMap<>();
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        int M = Integer.parseInt(bf.readLine());
        int a, b, c;
        int [][] cmap = new int [N+1][N+1];
        for(int i = 1; i <= N; i++){
            Arrays.fill(cmap[i], 20000001);
            cmap[i][i] = 0;
        }
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(bf.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            cmap[a][b] = Math.min(cmap[a][b], c);
        }
        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    if(cmap[i][k] + cmap[k][j] < cmap[i][j])
                        cmap[i][j] = cmap[i][k] + cmap[k][j];
                }
            }
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <=N; j++){
                if(cmap[i][j] >= 20000000) bw.write("0 ");
                else bw.write(Integer.toString(cmap[i][j])+" ");
            }
            bw.write("\n");
        }
        bw.close();
    }
}
