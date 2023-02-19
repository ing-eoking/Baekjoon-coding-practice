import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int a, b, c;
        int [][] cmap = new int [V+1][V+1];
        for(int i = 1; i <= V; i++){
            Arrays.fill(cmap[i], 4000001);
            cmap[i][i] = 0;
        }
        for(int i = 0; i < E; i++){
            st = new StringTokenizer(bf.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            cmap[a][b] = Math.min(cmap[a][b], c);
        }
        for(int k = 1; k <= V; k++){
            for(int i = 1; i <= V; i++){
                for(int j = 1; j <= V; j++){
                    if(cmap[i][k] + cmap[k][j] < cmap[i][j])
                        cmap[i][j] = cmap[i][k] + cmap[k][j];
                }
            }
        }
        int min = 4000001;
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(i == j) continue;
                min = Math.min(min, cmap[i][j] + cmap[j][i]);
            }
        }
        if(min < 4000001) bw.write(Integer.toString(min));
        else bw.write("-1");
        bw.close();
    }
}
