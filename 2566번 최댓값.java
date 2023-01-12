import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int max = -1, my = 0, mx = 0;
        for(int i = 1; i <= 9; i++){
            st = new StringTokenizer(bf.readLine());
            for(int j = 1; j <= 9; j++){
                int cur = Integer.parseInt(st.nextToken());
                if(cur > max){
                    max = cur;
                    my = i;
                    mx = j;
                }
            }
        }
        bw.write(Integer.toString(max)+ "\n");
        bw.write(Integer.toString(my)+ " "+Integer.toString(mx));
        bw.close();
    }
}
