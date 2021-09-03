package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Swea3234 {
    static BufferedWriter bw;
    static int ans;

    static void func(int n,int[] sinker,int dep,int[] arr,boolean[] check,int left,int right){
        if(dep==n){
            ans++;
            //System.out.println(Arrays.toString(arr));
            return;
        }

        for (int i = 0; i < n; i++) {
            if(check[i])continue;
            arr[dep]=i;
            check[i]=true;
            func(n,sinker,dep+1,arr,check,left+sinker[i],right);
            if(right+sinker[i]<=left)
                func(n,sinker,dep+1,arr,check,left,right+sinker[i]);
            check[i]=false;
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
            ans=0;

            int[] sinker=new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                sinker[i]=Integer.parseInt(st.nextToken());
            }

            func(n,sinker,0,new int[n],new boolean[n],0,0);
            bw.write("#"+tc+" "+ans+"\n");
        }




        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
