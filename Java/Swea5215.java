package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Swea5215 {
    static int[][] ham;
    static int ans,n,l;

    public static void func(int dep,int cal,int sat){
        if(dep==ham.length){
            if(cal<l&&sat>ans)
                ans=sat;
            return;
        }
        func(dep+1,cal,sat);
        if(cal+ham[dep][1]<=l)
            func(dep+1,cal+ham[dep][1],sat+ham[dep][0]);
    }

    public static void powerSet(int dep,boolean[] set){
        if(dep==ham.length){
            int sum=0,cal=0;
            for (int i = 0; i < set.length; i++) {
                if(!set[i])continue;
                sum+=ham[i][0];
                cal+=ham[i][1];
            }
            if(cal<=l&&sum>ans)
                ans=sum;
            return;
        }
        set[dep]=true;
        powerSet(dep+1,set);
        set[dep]=false;
        powerSet(dep+1,set);
    }

    public static void comb(int dep,int[] sel,int k,int bound){
        if(dep==bound){
            int sum=0,cal=0;
            for (int i = 0; i < dep; i++) {
                sum+=ham[sel[i]][0];
                cal+=ham[sel[i]][1];
                if(cal>l)
                    return;
            }
            if(sum>ans)ans=sum;
            return;
        }
        for (int i = k; i < ham.length; i++) {
            sel[dep]=i;
            comb(dep+1,sel,i+1,bound);
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine()); // 01010001
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            n=Integer.parseInt(st.nextToken());
            l=Integer.parseInt(st.nextToken());
            ans=0;

            ham=new int[n][2];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                ham[i][0]=Integer.parseInt(st.nextToken());
                ham[i][1]=Integer.parseInt(st.nextToken());
            }

            //func(0,0,0);
//            for (int i = 1; i <= n; i++) {
//                comb(0,new int[n],0,i);
//            }
            powerSet(0,new boolean[n]);

            bw.write("#"+tc+" "+ans+"\n");
        }

        br.close();
        bw.flush();
        bw.close();

    }
}

// backtracking

//    static int[][] ham;
//    static int ans,n,l;
//
//    public static void func(int dep,int cal,int sat){
//        if(dep==ham.length){
//            if(sat>ans)ans=sat;
//            return;
//        }
//        func(dep+1,cal,sat);
//
//          if(cal+ham[dep][1]<=l)
//            func(dep+1,cal+ham[dep][1],sat+ham[dep][0]);
//    }
//
//    public static void main(String[] args) throws Exception{
//        System.setIn(new FileInputStream("res/input.txt"));
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//
//        StringTokenizer st = new StringTokenizer(br.readLine()); // 01010001
//        int T=Integer.parseInt(st.nextToken());
//
//        for (int tc = 1; tc <= T; tc++) {
//            st = new StringTokenizer(br.readLine());
//            n=Integer.parseInt(st.nextToken());
//            l=Integer.parseInt(st.nextToken());
//            ans=0;
//
//            ham=new int[n][2];
//            for (int i = 0; i < n; i++) {
//                st = new StringTokenizer(br.readLine());
//                ham[i][0]=Integer.parseInt(st.nextToken());
//                ham[i][1]=Integer.parseInt(st.nextToken());
//            }
//
//            func(0,0,0);
//
//            bw.write("#"+tc+" "+ans+"\n");
//        }
//
//        br.close();
//        bw.flush();
//        bw.close();
//
//    }