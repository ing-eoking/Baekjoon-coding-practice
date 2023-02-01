import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int K = Integer.parseInt(st.nextToken()), N = Integer.parseInt(st.nextToken());
        long [] arr = new long [K];
        long mmax = 0;
        for(int i = 0; i < K; i++) if((arr[i] = Long.parseLong(bf.readLine()))> mmax) mmax = arr[i];
        long low = 1, high = mmax, mid;
        mmax = 0;
        while(low <= high){
            mid = (low + high)/2;
            long c = 0;
            for(int i = 0; i < K; i++) c += arr[i] / mid;
            if(c >= N){
                low = mid+1;
                if(mmax < mid) mmax = mid;
            }
            else high = mid -1;
        }
        bw.write(Long.toString(mmax));
        bw.close();
    }
}
