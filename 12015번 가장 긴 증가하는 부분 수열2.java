import java.io.*;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine()), num;
        TreeSet<Integer> set = new TreeSet<>();
        st = new StringTokenizer(bf.readLine());
        while(N-- >0){
            num = Integer.parseInt(st.nextToken());
            if(set.add(num) && set.higher(num) != null) set.remove(set.higher(num));
        }
        bw.write(Integer.toString(set.size()));
        bw.close();
    }
}
