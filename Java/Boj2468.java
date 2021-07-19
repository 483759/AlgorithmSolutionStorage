package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj2468 {
    static BufferedWriter bw;
    static int n;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean safe(){return this.x>=0&&this.x<n&&this.y>=0&&this.y<n;}
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        int[][] map=new int[n+1][n+1];

        int land=n*n;
        int ans=1;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
            }
        }

        int t=1;
        boolean[][] sink=new boolean[n+1][n+1];
        while(land!=0){
            land=0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(map[i][j]<=t)map[i][j]=-1;
                    else land++;
                }
            }

            boolean[][] visit=new boolean[n+1][n+1];

            int cnt=0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(map[i][j]!=-1&&visit[i][j]!=true){
                        cnt++;

                        Queue<Point> q=new LinkedList<>();
                        q.offer(new Point(j,i));

                        while(!q.isEmpty()){
                            Point cur=q.poll();

                            for (int k = 0; k < 4; k++) {
                                Point next=new Point(cur.x+dx[k],cur.y+dy[k]);
                                if(next.safe()&&map[next.y][next.x]!=-1&&!visit[next.y][next.x]){
                                    q.offer(next);
                                    visit[next.y][next.x]=true;
                                }
                            }
                        }
                    }
                }
            }
            if(cnt>ans)
                ans=cnt;

            t++;
        }



        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
