import java.io.*;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(bf.readLine()), n = 0;
        int [] arr = new int [N];
        StringBuffer answer = new StringBuffer();
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < N; i++)arr[i] = Integer.parseInt(bf.readLine());
        for(int i = 1; i <= N; i++){
            stack.push(i);
            answer.append("+\n");
            while(!stack.empty() && stack.peek() == arr[n]){
                answer.append("-\n");
                n++;
                stack.pop();
            }
        }
        if(stack.empty()) bw.write(answer.toString());
        else bw.write("NO\n");
        bw.close();
    }
}
