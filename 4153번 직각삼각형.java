import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int [] num = new int [3];
        while(true){
            st = new StringTokenizer(bf.readLine());
            for(int i = 0; i < 3; i++) num[i] = Integer.parseInt(st.nextToken());
            for(int i = 0; i < 3; i++) num[i] = num[i]*num[i];
            double total = (num[0] +  num[1] + num[2])/2;
            if(total == 0) break;
            if(total == (double)num[0] || total == (double)num[1] || total == (double)num[2])
                bw.write("right\n");
            else bw.write("wrong\n");
            bw.flush();
        }
        bw.close();
    }
}
