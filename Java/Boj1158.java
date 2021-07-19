package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj1158 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int k=Integer.parseInt(st.nextToken());
        Queue<Integer> q=new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            q.offer(i);
        }

        bw.write("<");
        while(!q.isEmpty()){
            for (int i = 0; i < k-1; i++) {
                q.offer(q.poll());
            }
            if(q.size()==1)bw.write(q.poll()+"");
            else bw.write(q.poll()+", ");
        }
        bw.write(">");





        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
