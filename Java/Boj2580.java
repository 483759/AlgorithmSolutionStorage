package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Boj2580 {
    static BufferedWriter bw;
    static boolean f=false;
    static ArrayList<point> list;
    static int[][] map;

    static class point{
        int r,c;

        public point(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public int zone(){
            if(this.r<3)return (this.c/3)+1;
            if(this.r<6)return (this.c/3)+4;
            return (this.c/3)+7;
        }
    }

    static void solve(int dep, boolean[][] row, boolean[][] col, boolean[][] sqr) throws IOException {
        if(f)return;
        if(dep==list.size()){
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    bw.write(map[i][j]+" ");
                }
                bw.write("\n");
            }
            f=true;
            return;
        }

        point cur=list.get(dep);
        for (int i = 1; i <= 9; i++) {
            if(row[cur.r][i]||col[cur.c][i]||sqr[cur.zone()][i])continue;

            map[cur.r][cur.c]=i;
            row[cur.r][i]=true;
            col[cur.c][i]=true;
            sqr[cur.zone()][i]=true;

            solve(dep+1,row,col,sqr);

            map[cur.r][cur.c]=0;
            row[cur.r][i]=false;
            col[cur.c][i]=false;
            sqr[cur.zone()][i]=false;
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;
        map=new int[9][9];
        boolean[][] row=new boolean[10][10],col=new boolean[10][10],sqr=new boolean[10][10];
        list=new ArrayList<>();

        for (int i = 0; i < 9; i++) {
            st = new StringTokenizer(br.readLine());
            map[i]=new int[9];
            for (int j = 0; j < 9; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
                if(map[i][j]==0)list.add(new point(i,j));
                else{
                    row[i][map[i][j]]=true;
                    col[j][map[i][j]]=true;
                    sqr[new point(i,j).zone()][map[i][j]]=true;
                }
            }
        }

        solve(0,row,col,sqr);
        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
