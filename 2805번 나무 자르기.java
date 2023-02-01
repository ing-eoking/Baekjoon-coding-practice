import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        long [] arr = new long [N];
        long mmax = 0;
        st = new StringTokenizer(bf.readLine());
        for(int i = 0; i < N; i++) if((arr[i] = Long.parseLong(st.nextToken()))> mmax) mmax = arr[i];
        long low = 0, high = mmax, mid;
        mmax = 0;
        while(low <= high){
            mid = (low + high)/2;
            long h = 0;
            for(int i = 0; i < N; i++) if(mid < arr[i]) h += (arr[i] - mid);
            if(h >= M){
                low = mid + 1;
                if(mmax < mid) mmax = mid;
            }
            else high = mid -1;
        }
        bw.write(Long.toString(mmax));
        bw.close();
    }
}
