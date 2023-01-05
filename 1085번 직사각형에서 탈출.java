import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int[] HS = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
        int[] SQ = {Integer.parseInt(st.nextToken()) - HS[0], Integer.parseInt(st.nextToken()) - HS[1]};
        bw.write(Integer.toString(Math.min(Math.min(HS[0],SQ[0]),Math.min(HS[1],SQ[1]))));
        bw.flush();
        bw.close();
    }
}
