package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj1520 {
    static BufferedWriter bw;
    static int n,m;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};
    static int[][] dp,map;

    static boolean safe(int x,int y){return x>=0&&x<m&&y>=0&&y<n;}

    static int dfs(int x,int y){
        if(x==m-1&&y==n-1)return 1;

        if(dp[y][x]!=-1)return dp[y][x];
        dp[y][x]=0;
        for (int i = 0; i < 4; i++) {
            int nx=x+dx[i],ny=y+dy[i];
            if(safe(nx,ny)&&(map[ny][nx]<map[y][x]))
                dp[y][x]+=dfs(nx,ny);
        }
        return dp[y][x];
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        map=new int[n+1][m+1];
        dp=new int[n+1][m+1];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i],-1);
        }

        bw.write(dfs(0,0)+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
