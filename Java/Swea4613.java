package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Swea4613 {
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
            int m=Integer.parseInt(st.nextToken());
            char[][] map=new char[n][m];
            int ans=Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                map[i]=st.nextToken().toCharArray();
            }

            for (int i = 0; i < n-2; i++) {
                for (int j = i+1; j < n-1; j++) {

                    int sum=0;
                    for (int k = 0; k <= i; k++) {
                        for (int l = 0; l < m; l++) {
                            if(map[k][l]!='W')sum++;
                        }
                    }
                    for (int k = i+1; k <= j; k++) {
                        for (int l = 0; l < m; l++) {
                            if(map[k][l]!='B')sum++;
                        }
                    }
                    for (int k = j+1; k < n; k++) {
                        for (int l = 0; l < m; l++) {
                            if(map[k][l]!='R')sum++;
                        }
                    }
                    ans=Math.min(ans,sum);
                }
            }



            bw.write("#"+tc+" "+ans+"\n");
        }

        br.close();
        bw.flush();
        bw.close();

    }
}
