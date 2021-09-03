package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Boj18868 {

    static BufferedWriter bw;

    static class Planet implements Comparable<Planet> {

        int size, idx;

        public Planet(int size, int idx) {
            this.size = size;
            this.idx = idx;
        }

        @Override
        public int compareTo(Planet o) {
            if(this.size==o.size)return o.idx-this.idx;
            return this.size - o.size;
        }
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int ans = 0;

        Planet[][] u = new Planet[m][n];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                u[i][j] = new Planet(Integer.parseInt(st.nextToken()), j);
            }
            Arrays.sort(u[i]);
            //bw.write(Arrays.toString(u[i])+"\n");
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                boolean b = true;
                for (int k = 0; k < n; k++) {
                    if (u[i][k].idx != u[j][k].idx) {
                        b = false;
                        break;
                    }
                }
                if (b) {
                    ans++;
                }
            }
        }

        bw.write(ans + "");

        br.close();
        bw.flush();
        bw.close();

    }
}
