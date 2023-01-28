import java.io.*;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine()), sum = 0, n;
        Stack<Integer> stack = new Stack<Integer>();
        while(N-- >0){
            n = Integer.parseInt(bf.readLine());
            if(n == 0){
                sum -= stack.peek();
                stack.pop();
            }
            else{
                sum += n;
                stack.push(n);
            }
        }
        bw.write(Integer.toString(sum));
        bw.close();
    }
}
