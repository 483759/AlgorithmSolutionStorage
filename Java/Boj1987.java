package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj1987 {
    static BufferedWriter bw;
    static char[][] map;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};
    static boolean[] apb=new boolean[26];
    static int r,c;

    static boolean safe(int x,int y){return x>=0&&x<c&&y>=0&&y<r;}

    static int dfs(int x,int y, int dep){
        apb[map[y][x]-'A']=true;
        int max=dep;
        for (int i = 0; i < 4; i++) {
            int nx=x+dx[i],ny=y+dy[i];
            if(!safe(nx,ny)||apb[map[ny][nx]-'A'])continue;
            max=Math.max(dfs(nx,ny,dep+1),max);
        }
        apb[map[y][x]-'A']=false;
        return max;
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        r=Integer.parseInt(st.nextToken());
        c=Integer.parseInt(st.nextToken());

        map=new char[r][c];
        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            map[i]=st.nextToken().toCharArray();
        }

        bw.write(dfs(0,0,1)+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
