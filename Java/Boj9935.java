package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Boj9935 {
    static BufferedWriter bw;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String str=st.nextToken();
        st = new StringTokenizer(br.readLine());
        String bomb=st.nextToken();
        String ans = "";
        Stack<Integer> idx=new Stack<>();
        idx.push(-1);

        for(int i=0;i<str.length();i++){
            char x=str.charAt(i);

            if(x==bomb.charAt(0))idx.push(0);
            else if(x==bomb.charAt(idx.peek()+1))idx.push(idx.peek()+1);
            else idx.push(-1);

            ans=ans.concat(String.valueOf(x));
            if(idx.peek()==bomb.length()-1) {
                ans=ans.substring(0,ans.length()-bomb.length());
                for (int j = 0; j < bomb.length(); j++) {
                    idx.pop();
                }
            }
        }

        if(ans.length()==0)bw.write("FRULA");
        else bw.write(ans+"");


        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
