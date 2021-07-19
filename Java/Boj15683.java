package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj15683 {
    static BufferedWriter bw;
    static int n,m;
    static int[] cctvSize={0,4,2,4,4,1},dx={1,0,-1,0},dy={0,1,0,-1};
    static int[][] cctvList={
        {0},
        {1,0,0,0},
        {1,0,1,0},
        {1,0,0,1},
        {1,1,1,0},
        {1,1,1,1}
    };
    static ArrayList<Point> points=new ArrayList<>();



    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        int[][] map=new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]>=1&&map[i][j]<=5)points.add(new Point(j,i));
            }
        }

        bw.write(solve(0, map, new boolean[n][m])+"");



        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }

    static void print(boolean[][] check) throws IOException {
        for (int i = 0; i < check.length; i++) {
            for (int j = 0; j < check[i].length; j++) {
                bw.write((check[i][j]?"1 ":"0 "));
            }
            bw.write('\n');
        }
        bw.write('\n');
    }

    private static int solve(int dep, int[][] map, boolean[][] check) throws IOException {
        if(dep==points.size()){
            int sum=0;

            for (int i = 0; i < check.length; i++) {
                for (int j = 0; j < check[i].length; j++) {
                    if(!check[i][j]&&map[i][j]==0)sum++;
                }
            }
            return sum;
        }
        int min=Integer.MAX_VALUE;
        Point cur=points.get(dep);
        int kind=map[cur.y][cur.x];

        boolean[][] tmp=new boolean[n][m];
        for (int i = 0; i < tmp.length; i++) {
            System.arraycopy(check[i],0,tmp[i],0,check[i].length);
        }
        for (int i = 0; i < cctvSize[kind]; i++) {
            for (int j = 0; j < 4; j++) {
                int ndir=(i+j)%4;
                if(cctvList[kind][j]==0)continue;

                Point next=new Point(cur.x,cur.y);
                while(next.safe()&&map[next.y][next.x]!=6){
                    check[next.y][next.x]=true;
                    next.x+=dx[ndir];
                    next.y+=dy[ndir];
                }
            }
            int val=solve(dep+1,map,check);
            min=Math.min(min,val);

            for (int j = 0; j < tmp.length; j++) {
                System.arraycopy(tmp[j],0,check[j],0,tmp[j].length);
            }
        }

        return min;
    }

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean safe(){
            return x>=0&&x<m&&y>=0&&y<n;
        }
    }
}
