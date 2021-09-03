package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj2961 {

    static int n;
    static int[][] arr;

    static int func(int dep, int k, int s, int b, boolean[] check) {
        if (dep == n) {
            if (k == 0) {
                return Integer.MAX_VALUE;
            }
            return Math.abs(s - b);
        }

        int min = func(dep + 1, k, s, b, check);
        check[dep] = true;
        min = Math.min(min, func(dep + 1, k + 1, s * arr[dep][0], b + arr[dep][1], check));
        check[dep] = false;
        return min;
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        bw.write(func(0, 0, 1, 0, new boolean[n]) + "");

        br.close();
        bw.flush();
        bw.close();

    }
}
