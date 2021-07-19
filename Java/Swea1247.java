package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Swea1247 {
    static int n,ans;
    static point cor,hom;
    static point[] usr;

    static class point{
        public int x;
        public int y;

        point(int x,int y){this.x=x;this.y=y;}
    }

    public static void main(String[] args) throws Exception{
        //System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        st = new StringTokenizer(in.readLine()); // 01010001
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            ans=Integer.MAX_VALUE;
            st = new StringTokenizer(in.readLine());
            n=Integer.parseInt(st.nextToken());

            st = new StringTokenizer(in.readLine());
            int x=Integer.parseInt(st.nextToken()),y=Integer.parseInt(st.nextToken());
            cor=new point(x,y);


            x=Integer.parseInt(st.nextToken());
            y=Integer.parseInt(st.nextToken());
            hom=new point(x,y);

            usr=new point[11];

            for (int i = 0; i < n; i++) {
                x=Integer.parseInt(st.nextToken());
                y=Integer.parseInt(st.nextToken());
                usr[i]=new point(x,y);
            }

            func(new int[n],0,new boolean[n]);
            out.write("#"+tc+" "+ans+"\n");
        }


        in.close();
        out.flush();
        out.close();
    }

    static int dist(point a,point b){
        return Math.abs(a.x-b.x)+Math.abs(a.y-b.y);
    }

    static void func(int[] sel,int dep,boolean[] check){
        if(dep==sel.length){
            int sum=dist(cor,usr[sel[0]]);
            for (int i = 0; i < sel.length-1; i++) {
                sum+=dist(usr[sel[i]],usr[sel[i+1]]);
            }
            sum+=dist(usr[sel[sel.length-1]],hom);
            if(sum<ans)ans=sum;
            return;
        }

        for (int i = 0; i < n; i++) {
            if(check[i])continue;
            sel[dep]=i;
            check[i]=true;
            func(sel,dep+1,check);
            check[i]=false;
        }
    }
}
