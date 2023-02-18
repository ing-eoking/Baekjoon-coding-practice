import java.awt.*;
import java.io.*;
import java.util.*;
 
public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static HashMap<Integer, ArrayList<Point>> dmap;
    static int n, m, t;
    public static int[] djk(int st){
        int[] dist = new int[n+1];
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
        while(!que.isEmpty()){
            q = que.poll();
            for (int i = 0; dmap.get(q.y) != null && i < dmap.get(q.y).size(); i++) {
                temp = dmap.get(q.y).get(i).x;
                d = dmap.get(q.y).get(i).y;
                if (dist[temp] > q.x + d) {
                    dist[temp] = q.x + d;
                    Point xy = new Point(dist[temp], temp);
                    que.add(xy);
                }
            }
        }
        return dist;
    }
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine());
        while(T-- > 0){
            dmap = new HashMap<>();
            st = new StringTokenizer(bf.readLine());
            n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken()); t = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(bf.readLine());
            int s = Integer.parseInt(st.nextToken()), g = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken());
            int a, b, d, x;
            for(int i = 0; i < m; i++){
                st = new StringTokenizer(bf.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                d = Integer.parseInt(st.nextToken());
                if(!dmap.containsKey(a)) dmap.put(a, new ArrayList<>());
                if(!dmap.containsKey(b)) dmap.put(b, new ArrayList<>());
                dmap.get(a).add(new Point(b, d));
                dmap.get(b).add(new Point(a, d));
            }
            int [] dist_st = djk(s), dist1 = djk(g), dist2 = djk(h);
            TreeSet<Integer> answer = new TreeSet<>();
            for(int i = 0; i < t; i++){
                x = Integer.parseInt(bf.readLine());
                if(dist_st[x] == dist1[h] + dist_st[g] + dist2[x]
                || dist_st[x] == dist1[x] + dist_st[h] + dist2[g]){
                    answer.add(x);
                }
            }
            Iterator it = answer.iterator();
            while(it.hasNext()) bw.write(it.next()+" ");
            bw.write("\n");

        }
        bw.close();

    }
}
