package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Swea1251 {
    static BufferedWriter bw;

    static class Point{
        double x,y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Node implements Comparable<Node>{
        int v;
        double w;

        public Node(int v, double w) {
            this.v = v;
            this.w = w;
        }


        @Override
        public int compareTo(Node o) {
            return Double.compare(this.w,o.w);
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            Point[] map=new Point[n];

            for (int i = 0; i < 2; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    if(i==0){
                        map[j]=new Point(0,0);
                        map[j].x=Double.parseDouble(st.nextToken());
                    }
                    else map[j].y=Double.parseDouble(st.nextToken());
                }

            }

            st = new StringTokenizer(br.readLine());
            double e=Double.parseDouble(st.nextToken());

            double[][] weight=new double[n+1][n+1];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    weight[i][j]=Math.sqrt(Math.pow(Math.abs(map[i].x-map[j].x),2)+Math.pow(Math.abs(map[i].y-map[j].y),2));
                }
            }
            double[] cost=new double[n+1];
            int[] prev=new int[n+1];
            boolean[] visit=new boolean[n+1];

            Arrays.fill(cost, Double.MAX_VALUE);
            Arrays.fill(prev,-1);

            PriorityQueue<Node> pq=new PriorityQueue<>();
            pq.offer(new Node(0,0));
            cost[0]=0;

            while(!pq.isEmpty()){
                int u=pq.poll().v;

                visit[u]=true;
                for (int i = 0; i < n; i++) {
                    double w=weight[u][i];

                    if(!visit[i]&&(cost[i]>w)){
                        pq.offer(new Node(i,w));
                        cost[i]=w;
                        prev[i]=u;
                    }
                }

            }

            double ans=0;
            for (int i = 0; i < n; i++) {
                ans+=e*Math.pow(cost[i],2);
            }


            ans=Math.round(ans);
            bw.write("#"+tc+" "+(long)ans+"\n");

        }





        br.close();
        bw.flush();
        bw.close();

    }
}
