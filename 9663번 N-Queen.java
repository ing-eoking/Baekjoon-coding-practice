import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int [] board = new int [15];
    static int n;
    static int c = 0;
    public static void path(int y){
        if(y == n){
            c++;
            return;
        }
        int k;
        for(int i  = 0; i < n; i++){
            k = 1;
            for(int j = 0; j < y; j++){
                if(board[j] == i || Math.abs(y-j) == Math.abs(i-board[j])){
                    k = 0;
                    break;
                }
            }
            if(k != 0){
                board[y] = i;
                path(y+1);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(bf.readLine());
        path(0);
        bw.write(Integer.toString(c));
        bw.close();
    }
}
