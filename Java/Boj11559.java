package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj11559 {
    static char[][] map;
    static int[][] visit;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};
    static BufferedWriter bw;

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean safe(){
            return x >= 0 && x < 6 && y >= 0 && y < 12;
        }
    }


    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;
        map=new char[12][6];

        for (int i = 0; i < 12; i++) {
            st = new StringTokenizer(br.readLine());
            map[i]=st.nextToken().toCharArray();
        }

        int ans=0;
        while(true) {
            ans++;
            int k=1,b=0;
            visit=new int[12][6];
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 6; j++) {
                    if (map[i][j] != '.') {
                        if (countConnectedPuyo(new Point(j, i), k) >= 4){
                            popPuyo(k);
                            b=1;
                        }
                        k++;
                    }
                }
            }
            if(b==1)gravity();
            else break;
            print();
        }

        bw.write(ans-1+"");

        br.close();
        bw.flush();
        bw.close();

    }

    private static void print() throws IOException {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                bw.write(map[i][j]);
            }
            bw.write("\n");
        }
    }

    private static void gravity() {
        Queue<Character> q=new LinkedList<>();

        for (int j = 0; j < 6; j++) {
            for (int i = 11; i >= 0; i--) {
                if (map[i][j] == '.')continue;
                q.offer(map[i][j]);
                map[i][j] = '.';
            }
            int r = 11;
            while (!q.isEmpty()) {
                map[r][j] = q.poll();
                r--;
            }
        }
    }

    private static void popPuyo(int k) {
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                if (visit[i][j] == k)
                    map[i][j] = '.';
    }

    private static int countConnectedPuyo(Point p, int k) {
        visit[p.y][p.x] = k;

        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            Point n=new Point(p.x+dx[i],p.y+dy[i]);
            if (!n.safe() || map[n.y][n.x] != map[p.y][p.x] || visit[n.y][n.x]!=0)continue;
            cnt+= countConnectedPuyo(n, k);
        }
        return cnt;
    }
}
