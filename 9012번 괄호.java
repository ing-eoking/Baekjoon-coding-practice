import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        while(N-- >0){
            int cor = 0;
            String str = bf.readLine();
            boolean tf = true;
            for(int i = 0; i < str.length(); i++){
                if(str.charAt(i) == '(') cor++;
                else if(str.charAt(i) == ')') cor--;
                if(cor < 0){
                    tf = false;
                    break;
                }
            }
            if(tf && cor == 0) bw.write("YES\n");
            else bw.write("NO\n");
        }
        bw.close();
    }
}
