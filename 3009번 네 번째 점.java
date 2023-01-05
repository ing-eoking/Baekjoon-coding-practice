import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        String [] X= new String[3];
        String [] Y= new String[3];
        for(int i = 0; i < 3; i++){
            st = new StringTokenizer(bf.readLine());
            X[i] = st.nextToken();
            Y[i] = st.nextToken();
        }
        bw.write(X[0].equals(X[1])?X[2]:(X[1].equals(X[2])?X[0]:X[1]));
        bw.write(" ");
        bw.write(Y[0].equals(Y[1])?Y[2]:(Y[1].equals(Y[2])?Y[0]:Y[1]));
        bw.flush();
        bw.close();
    }
}
