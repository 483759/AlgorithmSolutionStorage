package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Day12 {
    static char[][] map;
    static int n,m;
    static int[] dx={1,1,1},dy={-1,0,1};
    static int[][] pipe;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        pipe=new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            map[i]=st.nextToken().toCharArray();
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static boolean safe(int x,int y){return x>=0&&x<m&&y>=0&&y<n;}

    static void func(int row,int col){
        if(col==m){
            return;
        }
    }
}
