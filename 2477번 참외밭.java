import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int [][] move = new int[2][3];
        int [] MAX = {0,0};
        int [] IDX = {0,0};
        int Cost = Integer.parseInt(bf.readLine()), piv = 0;
        for(int i = 0; i < 6; i++) {
            st = new StringTokenizer(bf.readLine());
            st.nextToken();
            move[i % 2][i / 2] = Integer.parseInt(st.nextToken());
            if (MAX[i % 2] < move[i % 2][i / 2]) {
                MAX[i % 2] = move[i % 2][i / 2];
                IDX[i % 2] = i;
            }
        }
        if(IDX[0]*IDX[1] == 0 && IDX[0]+IDX[1] != 1) piv = 2;
        else piv = (Math.max(IDX[0], IDX[1]) + 2)%6;
        int piv2 = (piv+1)%6;
        bw.write(Integer.toString((MAX[0]*MAX[1] - move[piv%2][piv/2]*move[piv2%2][piv2/2])*Cost));
        bw.flush();
        bw.close();
    }
}
