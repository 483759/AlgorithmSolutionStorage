package Java;

import java.util.Scanner;

public class Swea2805 {
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};
    static int[][] arr;
    static int n;

    static void fill(int cx,int cy,int num,int d){
        if(num>n*n)return;

        arr[cy][cx]=num;

        int nx=cx+dx[d],ny=cy+dy[d];
        if(!(nx>=0&&nx<n&&ny>=0&&ny<n&&arr[ny][nx]==0))
            d=(d+1)%4;

        nx=cx+dx[d];
        ny=cy+dy[d];

        fill(nx,ny,num+1, d);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        int T=sc.nextInt();

        for (int tc = 1; tc <= T; tc++) {
            n=sc.nextInt();
            arr=new int[n+1][n+1];

            fill(0,0,1,0);

            System.out.println("#"+tc);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(arr[i][j]);
                }
                System.out.println();
            }
        }


    }
}
