import java.io.*;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine());
        Stack<Integer> stack = new Stack<Integer>();
        while(N-- > 0){
            st = new StringTokenizer(bf.readLine());
            String str = st.nextToken();
            if(str.equals("push")) stack.push(Integer.parseInt(st.nextToken()));
            else if(str.equals("pop") || str.equals("top"))
                if(stack.empty()) bw.write("-1\n");
                else{
                    bw.write(Integer.toString(stack.peek())+"\n");
                    if(str.equals("pop")) stack.pop();
                }
            else if(str.equals("size"))
                bw.write(Integer.toString(stack.size())+"\n");
            else if(str.equals("empty"))
                if(stack.empty()) bw.write("1\n");
                else bw.write("0\n");
        }
        bw.close();
    }
}
