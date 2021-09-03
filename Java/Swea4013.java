package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Swea4013 {
    static BufferedWriter bw;
    static int[][] gear,adj;
    static int[] dx={1,-1},idx;

    static boolean differ(int a,int b){
        if(a<b)return gear[a][(idx[a]+2)%8]!=gear[b][(idx[b]+6)%8];
        return gear[a][(idx[a]+6)%8]!=gear[b][(idx[b]+2)%8];
    }

    static void solution(int num, int dir, int pre){
        for (int i = 0; i < 2; i++) {
            int next=num+dx[i];
            if(next<0||next>=4||next==pre)continue;
            if(differ(num,next))solution(next,dir*(-1),num);
        }
        idx[num]=(idx[num]+dir+8)%8;
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            gear=new int[4][8];
            adj=new int[4][4];
            idx=new int[4];

            st = new StringTokenizer(br.readLine());
            int k=Integer.parseInt(st.nextToken());

            for (int i = 0; i < 4; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 8; j++) {
                    gear[i][j]=Integer.parseInt(st.nextToken());
                }
            }

            while(k--!=0){
                st = new StringTokenizer(br.readLine());
                int g=Integer.parseInt(st.nextToken());
                int d=Integer.parseInt(st.nextToken());
                solution(g-1,d*(-1),-1);
            }

            int ans=0;
            for (int i = 0; i < 4; i++) {
                if(gear[i][idx[i]]!=0)
                    ans+=(1<<i);
            }
            bw.write("#"+tc+" "+ans+"\n");
        }


        br.close();
        bw.flush();
        bw.close();

    }
}
