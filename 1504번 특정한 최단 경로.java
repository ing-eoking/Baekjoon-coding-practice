import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int V;
    public static HashMap<Integer, ArrayList<Point>> m = new HashMap<>();

    public static Point djk(int st, int ed1, int ed2) {
        int[] dist = new int[V + 1];
        int temp, d;
        PriorityQueue<Point> que = new PriorityQueue<>(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return o1.x - o2.x;
            }
        });
        que.add(new Point(0, st));
        Arrays.fill(dist, 10000000);
        dist[st] = 0;
        Point q;
        while (!que.isEmpty()) {
            q = que.poll();
            for (int i = 0; m.get(q.y) != null && i < m.get(q.y).size(); i++) {
                temp = m.get(q.y).get(i).x;
                d = m.get(q.y).get(i).y;
                if (dist[temp] > q.x + d) {
                    dist[temp] = q.x + d;
                    Point xy = new Point(dist[temp], temp);
                    que.add(xy);
                }
            }
        }
        return new Point(dist[ed1], dist[ed2]);
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(bf.readLine());
        V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken()), u, v, w;
        for(int i = 0; i < E; i++){
            st = new StringTokenizer(bf.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            if(!m.containsKey(u)) m.put(u, new ArrayList<>());
            if(!m.containsKey(v)) m.put(v, new ArrayList<>());
            m.get(u).add(new Point(v, w));
            m.get(v).add(new Point(u, w));
        }
        st = new StringTokenizer(bf.readLine());
        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());
        Point dist1 = djk(1,v1,v2);
        Point dist2 = djk(V, v2, v1);
        Point dist3 = djk(v1,v2,v2);
        Point dist = new Point(dist1.x + dist2.x + dist3.x, dist1.y + dist2.y + dist3.y);
        if(dist.x > 9999999 && dist.y > 9999999) bw.write("-1");
        else bw.write(Integer.toString(Math.min(dist.x, dist.y)));
        bw.close();
    }
}
