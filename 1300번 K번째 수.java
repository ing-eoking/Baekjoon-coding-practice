import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        long N = Long.parseLong(bf.readLine()), k = Math.min((long)(1e9), Long.parseLong(bf.readLine()));
        long left = 1, right = k, mid, cur = 0;
        while(left <= right){
            mid = (left + right)/2;
            long c = 0;
            for(int i = 1; i <= N; i++)
                c += Math.min(mid/i, N);
            if(c >= k){
                cur = mid;
                right = mid -1;
            }
            else left = mid + 1;
        }
        bw.write(Long.toString(cur));
        bw.close();
    }
}
