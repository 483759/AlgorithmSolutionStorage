package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Swea1238 {
    static BufferedWriter bw;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= 10; tc++) {
            int ans=0;
            st = new StringTokenizer(br.readLine());
            int len=Integer.parseInt(st.nextToken());
            int start=Integer.parseInt(st.nextToken());

            LinkedList<Integer>[] graph=new LinkedList[101];

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < len/2; i++) {
                int from=Integer.parseInt(st.nextToken());
                int to=Integer.parseInt(st.nextToken());

                if(graph[from]==null)graph[from]=new LinkedList<>();

                graph[from].offer(to);
            }

            Queue<Integer> q=new LinkedList<>();
            boolean[] visit=new boolean[101];

            q.offer(start);



            bw.write("#"+tc+" "+ans);
        }




        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
