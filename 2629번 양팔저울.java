import java.io.*;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static boolean [][] tf;
    static int [] w;
    static int N;
    public static void dp(int i, int num){
        if(i > N || tf[i][num]) return;
        tf[i][num] =true;
        dp(i+1, num + w[i]);
        dp( i+1, num);
        dp(i+1, Math.abs(num - w[i]));
    }
    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(bf.readLine());
        int sum = 0;
        st = new StringTokenizer(bf.readLine());
        w = new int[N+1];
        for(int i = 0; i < N; i++) sum += w[i] = Integer.parseInt(st.nextToken());
        tf = new boolean [N+1][sum+1];
        dp(0, 0);
        int X = Integer.parseInt(bf.readLine());
        st = new StringTokenizer(bf.readLine());
        while(X-- > 0) {
            int x = Integer.parseInt(st.nextToken());
            bw.write((x <= sum && tf[N][x])?"Y ":"N ");
        }
        bw.close();
    }
}
