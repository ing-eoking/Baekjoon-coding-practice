import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        int V = Integer.parseInt(st.nextToken()), E = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(bf.readLine()), u, v, w, temp, d;
        HashMap<Integer, ArrayList<Point>> m = new HashMap<>();
        for(int i = 0; i < E; i++){
            st = new StringTokenizer(bf.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            if(!m.containsKey(u)) m.put(u, new ArrayList<>());
            m.get(u).add(new Point(v, w));
        }
        int [] dist = new int [V+1];
        PriorityQueue<Point> que = new PriorityQueue<>(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return o1.x - o2.x;
            }
        });
        que.add(new Point(0, K));
        Arrays.fill(dist, 2000000);
        dist[K] = 0;
        Point q;
        while(!que.isEmpty()){
            q = que.poll();
            for(int i = 0; m.get(q.y) != null &&i < m.get(q.y).size(); i++) {
                temp = m.get(q.y).get(i).x;
                d = m.get(q.y).get(i).y;
                if (dist[temp] > q.x + d) {
                    dist[temp] = q.x + d;
                    Point xy = new Point(dist[temp], temp);
                    que.add(xy);
                }
            }
        }
        for(int i = 1; i <= V; i++)
            if(dist[i] > 1999999) bw.write("INF\n");
            else bw.write(Integer.toString(dist[i]) + "\n");
        bw.close();
    }
}
