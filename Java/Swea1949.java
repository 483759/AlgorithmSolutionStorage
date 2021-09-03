package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Swea1949 {
    static BufferedWriter bw;
    static int[][] map;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};
    static int n;

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static int dfs(Point cur, boolean[][] visit){
        int k=0;

        visit[cur.y][cur.x]=true;
        for (int i = 0; i < 4; i++) {
            int nx=cur.x+dx[i],ny=cur.y+dy[i];
            if(!(nx>=0&&nx<n&&ny>=0&&ny<n)||visit[ny][nx]||map[ny][nx]>=map[cur.y][cur.x])continue;
            int d=dfs(new Point(nx,ny),visit);
            k=Math.max(d,k);
        }

        visit[cur.y][cur.x]=false;
        return k+1;
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            int ans=0;

            st = new StringTokenizer(br.readLine());
            n=Integer.parseInt(st.nextToken());
            int k=Integer.parseInt(st.nextToken());
            map=new int[n][n];
            int high=0;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                map[i]=new int[n];
                for (int j = 0; j < n; j++) {
                    map[i][j]=Integer.parseInt(st.nextToken());
                    if(map[i][j]>high)
                        high=map[i][j];
                }
            }

            ArrayList<Point> mountain=new ArrayList<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(map[i][j]==high)
                        mountain.add(new Point(j,i));
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    for (int l = 1; l <= k; l++) {
                        map[i][j]--;
                        for (Point m:mountain) {
                            int d=dfs(m,new boolean[n][n]);
                            ans=Math.max(d,ans);
                        }
                    }
                    map[i][j]+=k;
                }

            }

            bw.write("#"+tc+" "+ans+"\n");
        }




        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
