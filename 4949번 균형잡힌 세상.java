import java.io.*;
import java.util.StringTokenizer;
import java.util.Stack;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        String str;
        while(!(str = bf.readLine()).equals(".")){
            Stack<Character> stack = new Stack<>();
            boolean tf = true;
            for(int i = 0; tf && i < str.length(); i++){
                char cur = str.charAt(i);
                if(cur != '(' && cur != ')' && cur != '[' && cur != ']') continue;
                if(cur == '(' || cur == '[') stack.push(cur);
                else if(stack.empty()) tf = false;
                else if(cur == ')' && stack.peek() == '(') stack.pop();
                else if(cur == ']' && stack.peek() == '[') stack.pop();
                else tf = false;
            }
            if(tf && stack.empty()) bw.write("yes\n");
            else bw.write("no\n");
        }
        bw.close();
    }
}
