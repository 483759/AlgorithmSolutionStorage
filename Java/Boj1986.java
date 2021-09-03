package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj1986 {
    static BufferedWriter bw;
    static int[][] map, dx={ {0,1,1,1,0,-1,-1,-1},{1,2,2,1,-1,-2,-2,-1} },dy={ {-1,-1,0,1,1,1,0,-1},{-2,-1,1,2,2,1,-1,-2} };
    static boolean[][] visit;
    static int n,m;

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        boolean safe(){return this.x>=0&&this.x<m&&this.y>=0&&this.y<n;}
    }

    static void input(int b){

    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        int ans=n*m;
        map=new int[n][m];
        visit=new boolean[n][m];
        ArrayList<Point> v[]=new ArrayList[3];
        for (int i = 0; i < n; i++) {
            Arrays.fill(visit[i],true);
        }
        for (int i = 1; i <= 3; i++) {
            st = new StringTokenizer(br.readLine());
            int t=Integer.parseInt(st.nextToken());
            v[i-1]=new ArrayList<>();

            for (int j = 0; j < t; j++) {
                int r=Integer.parseInt(st.nextToken());
                int c=Integer.parseInt(st.nextToken());

                map[r-1][c-1]=i;
                visit[r-1][c-1]=false;
                ans--;
                v[i-1].add(new Point(c-1,r-1));
            }
        }


        for(Point p: v[0]){
            for (int i = 0; i < 8; i++) {
                Point next=new Point(p.x+dx[0][i],p.y+dy[0][i]);
                while (next.safe() && map[next.y][next.x]==0) {
                    if (visit[next.y][next.x])ans--;
                    visit[next.y][next.x]= false;
                    next.x+=dx[0][i];
                    next.y+=dy[0][i];
                }
            }
        }

        for (Point p : v[1]) {
            for (int i = 0; i < 8; i++) {
                Point next=new Point(p.x+dx[1][i],p.y+dy[1][i]);
                if (next.safe() && map[next.y][next.x]==0) {
                    if (visit[next.y][next.x])ans--;
                    visit[next.y][next.x]= false;
                }
            }
        }

        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
