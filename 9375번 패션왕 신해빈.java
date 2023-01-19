import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(bf.readLine());
        while(T-- > 0){
            HashMap<String, Integer> map = new HashMap<String, Integer>();
            int N = Integer.parseInt(bf.readLine());
            while(N-- > 0){
                st = new StringTokenizer(bf.readLine());
                String name = st.nextToken(), Kind = st.nextToken();
                if(map.containsKey(Kind)) map.put(Kind, map.get(Kind).intValue() + 1);
                else map.put(Kind, 1);
            }
            int sum = 1;
            for(int i : map.values()) sum *= (i+1);
            bw.write(Integer.toString(sum-1)+"\n");
        }
        bw.close();
    }
}
