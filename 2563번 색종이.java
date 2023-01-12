import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        int area = 0;
        boolean [][] paper = new boolean[101][101];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(bf.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            for(int j = 0; j < 10; j++)
                for(int k = 0; k < 10; k++)
                    if(!paper[j+y][k+x]){
                        paper[j+y][k+x] = true;
                        area++;
                    }
        }
        bw.write(Integer.toString(area));
        bw.close();
    }
}
