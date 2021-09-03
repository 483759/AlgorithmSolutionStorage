package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Boj1197 {
    static BufferedWriter bw;

    static class Node implements Comparable<Node>{
        int v;
        int w;

        public Node(int v, int w) {
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Node o) {
            return this.w-o.w;
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int V=Integer.parseInt(st.nextToken());
        int E=Integer.parseInt(st.nextToken());

        ArrayList<Node>[] graph=new ArrayList[V+1];

        for (int i = 1; i <= V; i++) {
            graph[i]=new ArrayList<>();
        }

        for (int tc = 1; tc <= E; tc++) {
            st = new StringTokenizer(br.readLine());
            int u=Integer.parseInt(st.nextToken());
            int v=Integer.parseInt(st.nextToken());
            int w=Integer.parseInt(st.nextToken());
            graph[u].add(new Node(v,w));
            graph[v].add(new Node(u,w));
        }

        int[] cost=new int[V+1];
        int[] prev=new int[V+1];
        boolean[] visit=new boolean[V+1];

        Arrays.fill(cost,Integer.MAX_VALUE);
        Arrays.fill(prev,-1);
        Arrays.fill(visit,false);

        PriorityQueue<Node> pq=new PriorityQueue<>();

        pq.add(new Node(1,0));
        cost[1]=0;

        while(!pq.isEmpty()){
            int u=pq.poll().v;

            visit[u]=true;
            for(Node next:graph[u]){
                int v=next.v;
                int weight=next.w;

                if(!visit[v]&&cost[v]>weight){
                    cost[v]=weight;
                    prev[v]=u;
                    pq.add(new Node(v,cost[v]));
                }
            }
        }

        int sum=0;
        for (int i = 1; i <= V; i++) {
            sum+=cost[i];
        }

        bw.write(sum+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
