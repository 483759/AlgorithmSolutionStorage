package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj2458 {
    static BufferedWriter bw;
    static final int MAX=25005;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n,m;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        int[][] dist=new int[n+1][n+1];

        for (int i = 1; i <= n; i++) {
            Arrays.fill(dist[i],MAX);
            dist[i][i]=0;
        }
        for (int i = 0; i < m; i++) {
            int a,b;
            st = new StringTokenizer(br.readLine());
            a=Integer.parseInt(st.nextToken());
            b=Integer.parseInt(st.nextToken());
            dist[a][b]=1;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j]=Math.min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int ans=0;
        for (int i = 1; i <= n; i++) {
            int cnt=0;
            for (int j = 1; j <= n; j++) {
                if(dist[i][j]!=MAX||dist[j][i]!=MAX)
                    cnt++;
            }
            if(cnt==n)ans++;
        }

        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
