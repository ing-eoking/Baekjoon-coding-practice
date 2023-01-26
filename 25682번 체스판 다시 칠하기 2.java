import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        char [][] CH = {{'W','B'},{'B','W'}};
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken()), mmin = 999999999;
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int [][][] arr = new int [2][N+1][M+1];
        for(int i = 1; i <= N; i++){
            String s = bf.readLine();
            for(int j = 1; j <= M; j++){
                if(s.charAt(j-1) != CH[i%2][j%2]) arr[0][i][j]++;
                if(s.charAt(j-1) != CH[(i+1)%2][j%2]) arr[1][i][j]++;
                arr[0][i][j] += (arr[0][i-1][j] + arr[0][i][j-1] - arr[0][i-1][j-1]);
                arr[1][i][j] += (arr[1][i-1][j] + arr[1][i][j-1] - arr[1][i-1][j-1]);
                if(i >= K && j >= K){
                    int b1 = arr[0][i][j] - (arr[0][i-K][j] + arr[0][i][j-K] - arr[0][i-K][j-K]);
                    int b2 = arr[1][i][j] - (arr[1][i-K][j] + arr[1][i][j-K] - arr[1][i-K][j-K]);
                    int m = Math.min(b1, b2);
                    if(mmin > m) mmin = m;
                }
            }
        }
        bw.write(Integer.toString(mmin));
        bw.close();
    }
}
