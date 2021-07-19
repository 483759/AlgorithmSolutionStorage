package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj2072 {
    static int[][] map;
    static int[] dx={1,0,1,1},dy={0,1,1,-1};
    static int n;

    static boolean safe(int x,int y){ return x >= 0 && x < 19 && y >= 0 && y < 19; }

    static boolean isFiveStone(int x,int y,int d,int c){
        int sum = 0,max=0;
        while (safe(x, y)) {
            if (map[y][x] == c)sum++;
            else {
                if (sum == 5)
                    return true;
                sum = 0;
            }
            x += dx[d]; y += dy[d];
        }
        return sum==5;
    }

    static boolean count(int c){
        for (int i = 0; i < 19; i++) {
            if (isFiveStone(0, i, 0, c))return true;
            if (isFiveStone(i, 0, 1, c))return true;
            if (isFiveStone(0, i, 2, c))return true;
            if (isFiveStone(i, 0, 2, c))return true;
            if (isFiveStone(0, i, 3, c))return true;
            if (isFiveStone(i, 18, 3, c))return true;
        }
        return false;
    }


    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());

        map=new int[19][19];
        int i=1;
        for (i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int r=Integer.parseInt(st.nextToken());
            int c=Integer.parseInt(st.nextToken());
            map[r - 1][c - 1] = i % 2==1 ? 1 : 2;
            if (count(1))break;
            if (count(2))break;
        }
        if(i>n)bw.write(-1+"");
        else bw.write(i+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
