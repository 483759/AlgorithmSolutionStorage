package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Swea1868 {
    static BufferedWriter bw;
    static int[] dx={ 1,1,1,0,-1,-1,-1,0 },dy={ 1,0,-1,-1,-1,0,1,1 };
    static int n;

    static class Point{
        int c,x,y;

        public Point(int c, int x, int y) {
            this.c = c;
            this.x = x;
            this.y = y;
        }
    }


    static boolean safe(int x,int y){
        return x>=0&&x<n&&y>=0&&y<n;
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            n=Integer.parseInt(st.nextToken());
            int ans=0;
            char[][] map=new char[n][n];
            boolean[][] visit=new boolean[n][n];
            PriorityQueue<Point> pq=new PriorityQueue<>(new Comparator<Point>() {
                @Override
                public int compare(Point o1, Point o2) {
                    return Integer.compare(o1.c,o2.c);
                }
            });

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                map[i]=st.nextToken().toCharArray();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(map[i][j]=='*')continue;
                    Point p=new Point(0,j,i);
                    for (int k = 0; k < 8; k++) {
                        int nx=j+dx[k],ny=i+dy[k];
                        if(safe(nx,ny)&&map[ny][nx]=='*')
                            p.c++;
                    }
                    map[i][j]= (char)(p.c+'0');
                    pq.offer(p);
                }
            }

            while(!pq.isEmpty()){
                Point cur=pq.poll();
                if(visit[cur.y][cur.x])continue;

                ans++;
                visit[cur.y][cur.x]=true;
                if(map[cur.y][cur.x]!='0')continue;
                Queue<Point> q=new LinkedList<>();
                q.offer(cur);

                while(!q.isEmpty()){
                    Point p=q.poll();

                    for (int i = 0; i < 8; i++) {
                        int nx=p.x+dx[i],ny=p.y+dy[i];
                        if(!safe(nx,ny)||visit[ny][nx]||map[ny][nx]=='*')continue;
                        visit[ny][nx]=true;
                        if(map[ny][nx]=='0')q.offer(new Point(map[ny][nx],nx,ny));
                    }
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        bw.write(map[i][j]);
                    }
                    bw.write('\n');
                }
                bw.write('\n');
            }

            bw.write("#"+tc+" "+ans+'\n');

        }




        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
