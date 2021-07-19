package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Swea1767 {
    static BufferedWriter bw;
    static int[][] map;
    static boolean[][] visit;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};
    static int ans,len;

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
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
            ans=0;len=Integer.MAX_VALUE;

            map=new int[n+5][n+5];
            visit=new boolean[n+5][n+5];
            for (int i = 0; i <= n + 1; i++) {
                map[i][0] = map[i][n + 1] = map[0][i] = map[n + 1][i] = -1;
            }

            ArrayList<Point> p = new ArrayList<>();
            for (int i = 1; i <=n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 1; j <= n; j++) {
                    map[i][j]=Integer.parseInt(st.nextToken());
                    if(map[i][j]==1&&(i!=1&&i!=n&&j!=1&&j!=n))
                        p.add(new Point(j,i));
                }
            }

            dfs(p, 0, 0, 0);
            bw.write("#"+tc+" "+len+"\n");
        }




        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }

    private static void dfs(ArrayList<Point> p, int dep, int core, int wire) {
        if(dep==p.size()){
            if (core > ans) {
                ans = core;
                len = wire;
            }
            else if (core == ans && wire < len)
                len = wire;
            return;
        }

        dfs(p,dep+1,core,wire);
        for (int i = 0; i < 4; i++) {
            Point cur=new Point(p.get(dep).x,p.get(dep).y);
            int d=0;

            cur.x+=dx[i];cur.y+=dy[i];
            while(map[cur.y][cur.x]==0&&visit[cur.y][cur.x]==false){
                d++;
                cur.x+=dx[i];cur.y+=dy[i];
            }

            if(map[cur.y][cur.x]!=-1)continue;

            for (int j = 0; j < d; j++) {
                visit[p.get(dep).y + dy[i] * j][p.get(dep).x + dx[i] * j] = true;
            }

            dfs(p,dep + 1,core+1,wire+d);

            for (int j = 0; j < d; j++) {
                visit[p.get(dep).y + dy[i] * j][p.get(dep).x + dx[i] * j] = false;
            }
        }
    }
}
