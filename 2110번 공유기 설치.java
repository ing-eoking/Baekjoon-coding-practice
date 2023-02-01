import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        long [] arr = new long [N];
        for(int i = 0; i < N; i++) arr[i] = Long.parseLong(bf.readLine());
        Arrays.sort(arr);
        long low = 0, high = arr[arr.length - 1] - arr[0], mid, mmax = 0;
        while(low <= high){
            mid = (low + high)/2;
            long c = 1, st = arr[0];
            for(int i = 0; i < N; i++){
                if(arr[i] - st >= mid){
                    c++;
                    st = arr[i];
                }
            }
            if(c >= M){
                low = mid + 1;
                if(mmax < mid) mmax = mid;
            }
            else high = mid -1;
        }
        bw.write(Long.toString(mmax));
        bw.close();
    }
}
