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

public class Swea1249 {
    static BufferedWriter bw;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};
    static int n;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            n=Integer.parseInt(st.nextToken());

            int[][] map=new int[n][n];
            for (int i = 0; i < n; i++) {
                String s = new StringTokenizer(br.readLine()).nextToken();
                for (int j = 0; j < s.length(); j++) {
                    map[i][j]=s.charAt(j)-'0';
                }
            }

            int[][] cost=new int[n][n];
            boolean[][] visit=new boolean[n][n];
            for (int i = 0; i < n; i++) {
                Arrays.fill(cost[i], 1000000);
                Arrays.fill(visit[i], false);
            }

            PriorityQueue<Node> pq=new PriorityQueue<>();
            pq.offer(new Node(0,new Point(0,0)));
            cost[0][0]=0;

            while(!pq.isEmpty()){
                Point cur=pq.poll().point;
                if(visit[cur.y][cur.x])continue;

                visit[cur.y][cur.x]=true;
                for(int i=0;i<4;i++){
                    Point next=new Point(cur.x+dx[i],cur.y+dy[i]);
                    if(!next.isSafe())continue;
                    if(cost[next.y][next.x]>cost[cur.y][cur.x]+map[next.y][next.x]){
                        cost[next.y][next.x]=cost[cur.y][cur.x]+map[next.y][next.x];
                        pq.offer(new Node(cost[next.y][next.x],next));
                    }
                }

            }

            bw.write("#"+tc+" "+cost[n-1][n-1]+"\n");


        }




        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean isSafe(){
            return this.x>=0&&x<n&&y>=0&&y<n;
        }
    }

    static class Node implements Comparable<Node>{
        int cost;
        Point point;

        public Node(int cost, Point point) {
            this.cost = cost;
            this.point = point;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.cost,o.cost);
        }
    }
}
