package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class Boj2493 {
    static class tower{
        int idx;
        int h;

        public tower(int idx,int h){
            this.idx=idx;
            this.h=h;
        }
    }


    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine()); // 01010001
        int n=Integer.parseInt(st.nextToken());

        Stack<tower> t=new Stack<>();
        Stack<tower> s=new Stack<>();

        st = new StringTokenizer(br.readLine()); // 01010001
        for (int i = 0; i < n; i++) {
            int h=Integer.parseInt(st.nextToken());
            t.push(new tower(i+1,h));
        }
        int[] ans=new int[n+1];

        while(!t.isEmpty()){
            tower cur=t.pop();

            while(!s.isEmpty()&&(s.peek().h<=cur.h)){
                ans[s.pop().idx]=cur.idx;
            }
            s.push(cur);
        }
        s.clear();
        for (int i = 1; i < ans.length; i++) {
            bw.write(ans[i]+" ");
        }
        bw.write("\n");
        br.close();
        bw.flush();
        bw.close();
    }
}
