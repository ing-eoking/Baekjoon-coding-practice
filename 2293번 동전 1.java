import java.io.*;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int [] coin = new int [n], cost = new int [k+1];
        for(int i = 0; i < n; i++) {
            coin[i] = Integer.parseInt(bf.readLine());
            if(coin[i] > k) continue;
            cost[coin[i]]++;
            for(int j = coin[i]; j <= k; j++){
                cost[j] += cost[j - coin[i]];
            }
        }
        bw.write(Integer.toString(cost[k]));
        bw.close();
    }
}
