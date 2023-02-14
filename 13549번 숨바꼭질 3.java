import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int [] dist = new int[100001];
        Arrays.fill(dist, 999999);
        dist[N] = 0;
        Point q;
        PriorityQueue<Point> que = new PriorityQueue<>(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return o1.x - o2.x;
            }
        });
        que.add(new Point(0, N));
        while(!que.isEmpty()){
            q = que.poll();
            if(q.y == K) break;
            if(q.y > 0 && dist[q.y - 1] > dist[q.y] + 1){
                dist[q.y - 1] = dist[q.y] + 1;
                que.add(new Point(dist[q.y -1], q.y - 1));
            }
            if(q.y < 100000 && dist[q.y + 1] > dist[q.y] + 1){
                dist[q.y + 1] = dist[q.y] +1;
                que.add(new Point(dist[q.y + 1], q.y + 1));
            }
            if(q.y*2 <= 100000 && dist[q.y * 2] >  dist[q.y]){
                dist[q.y*2] = dist[q.y];
                que.add(new Point(dist[q.y*2], q.y*2));
            }
        }
        bw.write(Integer.toString(dist[K]));
        bw.close();
    }
}
