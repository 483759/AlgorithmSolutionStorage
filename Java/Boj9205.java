package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj9205 {
    static BufferedWriter bw;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());
            n+=2;

            int[][] dist=new int[n][n];
            int[][] map=new int[n][2];
            for (int i = 0; i < n; i++) {
                Arrays.fill(dist[i], Integer.MAX_VALUE);
            }
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                map[i][0]=Integer.parseInt(st.nextToken());
                map[i][1]=Integer.parseInt(st.nextToken());
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(i==j){
                        dist[i][j]=0;continue;
                    }
                    dist[i][j]=Math.abs(map[i][0]-map[j][0])+Math.abs(map[i][1]-map[j][1]);
                    if(dist[i][j]>1000)dist[i][j]=Integer.MAX_VALUE;
                }
            }

            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if(dist[i][k]==Integer.MAX_VALUE||dist[k][j]==Integer.MAX_VALUE)continue;
                        if(dist[i][j]>dist[i][k]+dist[k][j])
                            dist[i][j]=Math.min(dist[i][k]+dist[k][j],dist[i][j]);
                    }
                }
            }
            if(dist[0][n-1]!=Integer.MAX_VALUE)
                bw.write("happy\n");
            else bw.write("sad\n");
        }

        br.close();
        bw.flush();
        bw.close();

    }
}
