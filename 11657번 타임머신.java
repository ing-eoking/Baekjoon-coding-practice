import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static HashMap<Point, Long> hash = new HashMap<>();
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int A, B, C;
        Point xy;
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(bf.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            xy = new Point(A, B);
            if(hash.containsKey(xy) && (long)C > hash.get(xy)) continue;
            hash.put(xy, (long)C);
        }
        long [] dist = new long[N+1];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[1] = 0;
        for(int i = 1; i <= N; i++){
            for(Point key : hash.keySet()){
                if(dist[key.x] != Long.MAX_VALUE && dist[key.y] > dist[key.x] + hash.get(key)){
                    dist[key.y] = dist[key.x] + hash.get(key);
                    if(i == N){
                        bw.write("-1");
                        bw.close();
                        System.exit(0);
                    }
                }
            }
        }
        for(int i = 2; i <= N; i++){
            if(dist[i] == Long.MAX_VALUE) bw.write("-1\n");
            else bw.write(Long.toString(dist[i])+"\n");
        }
        bw.close();
    }
}
