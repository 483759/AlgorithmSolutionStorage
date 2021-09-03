package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj17406 {
    static class Operation{
        int r;
        int c;
        int s;
        Operation(int r,int c,int s){
            this.r=r;
            this.c=c;
            this.s=s;
        }
    }

    static int[][] origin;
    static BufferedReader br;
    static BufferedWriter bw;
    static Operation[] op;
    static int ans=Integer.MAX_VALUE;

    static void rotate(int r,int c,int w,int h,int[][] arr) throws IOException {
        if(w<=1||h<=1)return;
        
        Queue<Integer> q=new LinkedList<>();
        q.offer(0);


        for (int i = 0; i < w; i++) { //위쪽 행
            q.offer(arr[r][c+i]);
            arr[r][c+i]=q.poll();
        }

        for (int i = 1; i < h; i++) { //오른쪽 열
            q.offer(arr[r+i][c+w-1]);
            arr[r+i][c+w-1]=q.poll();
        }

        for (int i = w-2; i >=0 ; i--) {   //아래쪽 행
            q.offer(arr[r+h-1][c+i]);
            arr[r+h-1][c+i]=q.poll();
        }

        for (int i = h-2; i >=0; i--) {   //왼쪽 열
            q.offer(arr[r+i][c]);
            arr[r+i][c]=q.poll();
        }



        rotate(r+1,c+1,w-2,h-2,arr);
    }

    public static void dfs(int dep,int[] seq,boolean[] chk) throws IOException {
        if(dep==op.length){
            int[][] copy=new int[origin.length][origin[0].length];
            for (int i = 0; i < origin.length; i++) {
                System.arraycopy(origin[i],0,copy[i],0,origin[i].length);
            }
            for (int i = 0; i < seq.length; i++) {
                Operation o=op[seq[i]];
                rotate(o.r-o.s,o.c-o.s,2*o.s+1,2*o.s+1,copy);
            }
            print(copy);
            int s=sum(copy);
            ans=Math.min(ans,s);
            return;
        }

        for (int i = 0; i < op.length; i++) {
            if(chk[i])continue;
            seq[dep]=i;
            chk[i]=true;
            dfs(dep+1,seq,chk);
            chk[i]=false;
        }
    }

    private static int sum(int[][] arr) {
        int k=Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            int sum=0;
            for (int j = 0; j < arr[i].length; j++) {
                sum+=arr[i][j];
            }
            k=Math.min(k,sum);
        }
        return k;
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int r=Integer.parseInt(st.nextToken());
        origin=new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                origin[i][j]=Integer.parseInt(st.nextToken());
            }
        }

        op=new Operation[r];
        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int c=Integer.parseInt(st.nextToken());
            op[i]=new Operation(a-1,b-1,c);
        }
        dfs(0,new int[r],new boolean[r]);

        bw.write(ans+"");
        //print(origin);
        br.close();
        bw.flush();
        bw.close();

    }

    private static void print(int[][] arr) throws IOException {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                bw.write(arr[i][j]+" ");
            }
            bw.write("\n");
        }
        bw.write("\n");
    }
}
