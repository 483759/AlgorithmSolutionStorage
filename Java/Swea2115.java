package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Swea2115 {
    static BufferedWriter bw;
    static int n,m,c;
    static ArrayList<Point> list;

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int getHoney(int dep, int sum, int[] beeHive, boolean[] check){
        if(dep==beeHive.length){
            int k=0;
            for (int i = 0; i < check.length; i++) {
                if(check[i])k+=beeHive[i]*beeHive[i];
            }
            return k;
        }

        int max=getHoney(dep+1,sum,beeHive,check);
        for (int i = dep; i < beeHive.length; i++) {
            if(beeHive[i]+sum>c)continue;
            check[i]=true;
            int honey=getHoney(i+1, sum+beeHive[i], beeHive, check);
            max=Math.max(max,honey);
            check[i]=false;
        }
        return max;
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
            m=Integer.parseInt(st.nextToken());
            c=Integer.parseInt(st.nextToken());

            int[][] map=new int[n][n];
            list=new ArrayList<>();
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    map[i][j]=Integer.parseInt(st.nextToken());
                    if(j+m<=n)
                        list.add(new Point(j,i));
                }
            }

            int ans=0;
            for (int i = 0; i < list.size(); i++) {
                for (int j = i+1; j < list.size(); j++) {
                    Point a=list.get(i),b=list.get(j);
                    if(a.y==b.y&&(a.x+m>b.x))continue;

                    int[] beehive=new int[m];
                    for (int k = 0; k < m; k++) {
                        beehive[k]=map[a.y][a.x+k];
                    }
                    int ha=getHoney(0,0, beehive, new boolean[m]);
                    for (int k = 0; k < m; k++) {
                        beehive[k]=map[b.y][b.x+k];
                    }
                    int hb=getHoney(0,0, beehive, new boolean[m]);
                    ans=Math.max(ans,ha+hb);
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
