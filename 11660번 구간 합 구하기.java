import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int [][] a = new int [N+1][N+1];
        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(bf.readLine());
            for(int j = 1; j <= N; j++)
                a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + Integer.parseInt(st.nextToken());
        }
        while(M-- > 0){
            st = new StringTokenizer(bf.readLine());
            int [] c1 = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
            int [] c2 = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
            int sum = a[c2[0]][c2[1]];
            sum -= (a[c1[0]-1][c2[1]] + a[c2[0]][c1[1]-1] - a[c1[0]-1][c1[1]-1]);
            bw.write(Integer.toString(sum)+"\n");
        }
        bw.close();
    }
}
