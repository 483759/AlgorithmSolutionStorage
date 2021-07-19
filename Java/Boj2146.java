package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj2146 {

    static BufferedWriter bw;
    static int[][] map;
    static int[][][] visit;
    static int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    static int n,ans=Integer.MAX_VALUE;
    static ArrayList<Point> bound = new ArrayList<>();

    static class Point {

        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public boolean safe() {
            return this.x >= 0 && this.x < n && this.y >= 0 && this.y < n;
        }
    }

    static void boundBFS(Point p) {
        Queue<Point> q = new LinkedList<>();

//        visit[p.y][p.x] = true;
//        q.offer(p);
//        while (!q.isEmpty()) {
//            Point cur = q.poll();
//
//            for (int i = 0; i < 4; i++) {
//                Point next = new Point(cur.x + dx[i], cur.y + dy[i]);
//                if (!next.safe() || visit[next.y][next.x]) {
//                    continue;
//                }
//                if (map[next.y][next.x] != 0) {
//                    map[cur.y][cur.x] = -map[next.y][next.x];
//                    bound.add(cur);
//                } else {
//                    visit[next.y][next.x] = true;
//                    q.offer(next);
//                }
//            }
//        }

        return;
    }

    static void landNumBFS(Point p, int k) {
        Queue<Point> q = new LinkedList<>();

//        visit[p.y][p.x] = true;
//        q.offer(p);
//        while (!q.isEmpty()) {
//            Point cur = q.poll();
//
//            map[cur.y][cur.x] = k;
//            for (int i = 0; i < 4; i++) {
//                Point next = new Point(cur.x + dx[i], cur.y + dy[i]);
//                if (!next.safe() || visit[next.y][next.x] || map[next.y][next.x] != 1) {
//                    continue;
//                }
//                visit[next.y][next.x] = true;
//                q.offer(next);
//            }
//        }

        return;
    }

    static int bridgeBFS(Point p){
        Queue<Point> q = new LinkedList<>();
        int[][] visit=new int[n][n];

        int num=-map[p.y][p.x];
        visit[p.y][p.x] = 1;
        q.offer(p);
        while (!q.isEmpty()) {
            Point cur = q.poll();

            if(map[cur.y][cur.x]>0)return visit[cur.y][cur.x]-1;
            for (int i = 0; i < 4; i++) {
                Point next = new Point(cur.x + dx[i], cur.y + dy[i]);
                if (!next.safe() || visit[next.y][next.x]!=0 || map[next.y][next.x] == num) {
                    continue;
                }
                visit[next.y][next.x] = visit[cur.y][cur.x]+1;
                q.offer(next);
            }
        }
        return -1;
    }

    public static void print() throws IOException {
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                bw.write(map[i][j] + "");
            }
            bw.write("\n");
        }
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        visit = new int[2][n][n];
        Arrays.fill(visit,0);
        int num = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1 && visit[0][i][j]==0) {
                    landNumBFS(new Point(j, i), num++);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 0 && visit[1][i][j]==0) {
                    boundBFS(new Point(j, i));
                }
            }
        }

        for (Point b:bound) {
            int k=bridgeBFS(b);
            ans=Math.min(k,ans);
        }

        //print();

        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
