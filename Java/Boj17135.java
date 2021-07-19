package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Boj17135 {
    static BufferedWriter bw;
    static int[][] map;
    static int n,m,d,ans;
    static ArrayList<Point> enemy=new ArrayList<>();

    public static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static void comb(int k,int dep,int[] arr) throws IOException {
        if(dep==3){
            int score=game(arr);
            ans=Math.max(score,ans);
            return;
        }

        for (int i = k; i < m; i++) {
            arr[dep]=i;
            comb(i+1,dep+1,arr);
        }
    }

    static int distance(Point a,Point b){
        return Math.abs(a.x-b.x)+Math.abs(a.y-b.y);
    }

    private static int game(int[] arr) {
        int row=n,cnt=0;
        boolean[][] check=new boolean[n][m];
        boolean[] E=new boolean[enemy.size()];
        Arrays.fill(E,true);

        while(row>0){
            Point[] kill=new Point[3];
            for (int i = 0; i < arr.length; i++) {
                int dist=d;
                Point cur=new Point(arr[i],row);
                kill[i]=new Point(m,-1);

                for (int j=0;j<E.length;j++) {
                    if(!E[j])continue;
                    Point e=enemy.get(j);
                    int ad=distance(cur,e);
                    if((ad==dist&&e.x<kill[i].x)||(ad<dist)){
                        dist=distance(cur,e);
                        kill[i]=e;
                    }
                }
            }

            for (Point k:kill) {
                if(k.y==-1||check[k.y][k.x])continue;
                cnt++;
                check[k.y][k.x]=true;
            }

            row--;
            for (int i = 0; i < E.length; i++) {
                if(enemy.get(i).y==row||check[enemy.get(i).y][enemy.get(i).x]){
                    E[i]=false;
                }
            }

        }
        return cnt;
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        d=Integer.parseInt(st.nextToken());

        map=new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
                if(map[i][j]==1)enemy.add(new Point(j,i));
            }
        }

        comb(0,0,new int[3]);

        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
