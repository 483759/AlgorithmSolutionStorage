package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Boj10799 {

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine()); // 01010001
        String str=st.nextToken();

        Stack<Integer> s=new Stack<>();
        int ans=0;
        for (int i=0;i<str.length();i++) {
            char c=str.charAt(i);

            if(c=='(')
                s.push(1);
            else{
                s.pop();
                ans+=s.size();
            }
        }
        bw.write(ans);

        br.close();
        bw.flush();
        bw.close();

    }
}
