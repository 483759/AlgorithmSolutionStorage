package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Swea1861 {

    static int n, ans;
    static int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    static int[][] map;
    static point p;

    static class point {

        int x;
        int y;

        point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        static boolean safe(int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < n;
        }
    }

    public static int func(point cur, int dep) {
        boolean b = false;

        int k = dep;
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (!point.safe(nx, ny) || (map[cur.y][cur.x] + 1 != map[ny][nx])) {
                continue;
            }

            int d = func(new point(nx, ny), dep + 1);
            if (d > k) {
                k = d;
            }
        }

        return k;
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            map = new int[n + 1][n + 1];
            ans = 0;
            p = new point(n, n);
            map[n][n] = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    point cur = new point(j, i);
                    int k = func(cur, 1);
                    if ((k == ans && (map[cur.y][cur.x] < map[p.y][p.x]))
                        || (k > ans)) {
                        ans = k;
                        p = cur;
                    }
                }
            }
            bw.write("#" + tc + " " + map[p.y][p.x] + " " + ans + "\n");
        }

        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
