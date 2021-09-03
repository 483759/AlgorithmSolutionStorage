package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj2563 {
    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());
        int[][] arr=new int[105][105];

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int x=Integer.parseInt(st.nextToken());
            int y=Integer.parseInt(st.nextToken());

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    arr[y+i][x+j]=1;
                }
            }
        }

        int ans=0;
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                if(arr[i][j]==1)
                    ans++;
            }
        }

        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
