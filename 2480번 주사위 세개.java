import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int [] D = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
        if(D[0] == D[1] && D[1] == D[2]) bw.write(Integer.toString(10000+D[0]*1000));
        else if(D[0] == D[1] || D[0] == D[2]) bw.write(Integer.toString(1000 + D[0]*100));
        else if(D[1] == D[2]) bw.write(Integer.toString(1000 + D[1]*100));
        else bw.write(Integer.toString(Math.max(Math.max(D[0],D[1]),D[2])*100));
        bw.flush();
        bw.close();
    }
}
