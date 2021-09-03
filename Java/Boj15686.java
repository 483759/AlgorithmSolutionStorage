package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Boj15686 {
    static int n,m,ans=Integer.MAX_VALUE;
    static int[][] map;
    static ArrayList<Point> home, chicken;

    static class Point{
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void powerSet(int check,int dep,int k){
        if(dep==chicken.size()){
            int sum=0;

            for (Point h:home) {
                int dist=3000;
                for (int i = 0; i < chicken.size(); i++) {
                    if((check&(1<<i))==0)continue;
                    dist=Math.min(dist,Math.abs(chicken.get(i).x-h.x)+Math.abs(chicken.get(i).y-h.y));
                }
                sum+=dist;
            }

            ans=Math.min(ans,sum);
            return;
        }

        if(k<m) {
            check|=(1<<dep);
            powerSet(check, dep + 1, k + 1);
            check&=~(1<<dep);
        }
        powerSet(check,dep+1,k);
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        map=new int[n][n];
        home=new ArrayList<>();
        chicken=new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
                if(map[i][j]==1)home.add(new Point(j,i));
                if(map[i][j]==2)chicken.add(new Point(j,i));
            }
        }

        powerSet(0,0,0);
        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
