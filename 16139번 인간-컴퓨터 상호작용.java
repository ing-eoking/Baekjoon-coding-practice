import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        String s = bf.readLine();
        int [][] arr = new int [26][s.length() + 1];
        for(int i = 0; i < s.length(); i++){
            arr[s.charAt(i) - 'a'][i + 1] += 1;
            for(int j = 0; j < 26; j++) arr[j][i+1] += arr[j][i];
        }
        int N = Integer.parseInt(bf.readLine()), D1, D2, n;
        while(N-- > 0){
            st = new StringTokenizer(bf.readLine());
            char c = st.nextToken().charAt(0);
            D1 = Integer.parseInt(st.nextToken());
            D2 = Integer.parseInt(st.nextToken());
            n = arr[c - 'a'][D2+1] - arr[c - 'a'][D1];
            bw.write(Integer.toString(n)+ "\n");
        }
        bw.close();
    }
}
