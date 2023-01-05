import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine());
        int [][] Turret = new int[2][2];
        int [] R = new int [2];
        for(int i = 0; i < T; i++){
            StringTokenizer st = new StringTokenizer(bf.readLine());
            for(int j = 0; j < 2; j++){
                Turret[j][0] = Integer.parseInt(st.nextToken());
                Turret[j][1] = Integer.parseInt(st.nextToken());
                R[j] = Integer.parseInt(st.nextToken());
            }
            double dist = Math.sqrt(Math.pow(Turret[0][0] - Turret[1][0],2) + Math.pow(Turret[0][1] - Turret[1][1],2));
            double R1 = Math.abs(R[0]-R[1]);
            double R2 = R[0] + R[1];
            if (dist == 0 && R[0] == R[1]) bw.write("-1");
            else if (R1 == dist || R2 == dist) bw.write("1");
            else if (R1 < dist && dist < R2) bw.write("2");
            else bw.write("0");
            if(i + 1 != T) bw.write("\n");
            bw.flush();
        }
        bw.close();
    }
}
