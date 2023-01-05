import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine());
        for(int t = 0; t < T; t++){
            st = new StringTokenizer(bf.readLine());
            int [] S = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
            int [] D = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
            int n = Integer.parseInt(bf.readLine());
            int over = 0;
            for(int i = 0; i < n; i++){
                st = new StringTokenizer(bf.readLine());
                int [] star = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
                int r = Integer.parseInt(st.nextToken());
                int dist1 = (star[0]-S[0])*(star[0]-S[0])+(star[1]-S[1])*(star[1]-S[1]);
                int dist2 = (star[0]-D[0])*(star[0]-D[0])+(star[1]-D[1])*(star[1]-D[1]);
                r = r*r;
                if((dist1 < r) ^ (dist2 < r)) over= over+1;
            }
            bw.write(Integer.toString(over)+"\n");
            bw.flush();
        }
        bw.close();
    }
}
