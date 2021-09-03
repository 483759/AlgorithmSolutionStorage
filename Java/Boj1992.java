package Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1992 {
    static char[][] map;
    static StringBuilder sb;

    public static void quadTree(int r,int c,int k) throws IOException {
        if(k==1){
            sb.append(map[r][c]);
            return;
        }

        boolean b=true;
        L:for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if(map[r+i][c+j]!=map[r][c]){
                    b=false;
                    break L;
                }
            }
        }

        if(!b){
            sb.append("(");
            quadTree(r,c,k/2);
            quadTree(r,c+k/2,k/2);
            quadTree(r+k/2,c,k/2);
            quadTree(r+k/2,c+k/2,k/2);
            sb.append(")");
        }else{
            sb.append(map[r][c]);
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n=Integer.parseInt(br.readLine());

        map=new char[n][n];
        for (int i = 0; i < n; i++) {
            map[i]=br.readLine().toCharArray();
        }
        sb=new StringBuilder();

        quadTree(0,0,n);
        System.out.println(sb);

        br.close();
    }
}
