package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Swea9229 {
    static int[] arr;
    static int n,m,ans;

    public static void func(int dep,int gram,int k){
        if(dep==2){
            if(gram>ans)ans=gram;
            return;
        }

        for (int i = k; i < arr.length; i++) {
            if(gram+arr[i]<=m)
                func(dep+1,gram+arr[i],i);
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            ans=-1;
            st = new StringTokenizer(br.readLine());
            n=Integer.parseInt(st.nextToken());
            m=Integer.parseInt(st.nextToken());

            arr=new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i]=Integer.parseInt(st.nextToken());
            }
            func(0,0,0);
            bw.write("#"+tc+" "+ans+"\n");
        }

        br.close();
        bw.flush();
        bw.close();

    }
}
