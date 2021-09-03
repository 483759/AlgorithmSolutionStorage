package Java;

import java.util.Scanner;

public class Swea1210 {
    static int[] dx = {-1,1,0};//<-->^ 왼오위
    static int[] dy = {0,0,-1};//
    static int[][] leader = new int[100][100];

    static int func(int gox,int goy,int d){
        if(goy==0){  //끝
            return gox;
        }

        if(gox-1>=0 && leader[goy][gox-1]>0 && d!=1 ){  // 위나 왼쪽에서 왼쪽으로 갈수 있다면  왼쪽으로
            d=0;
        }
        if(gox+1<100 && leader[goy][gox+1]>0 && d!=0 ){ //오른쪽으로
            d=1;
        }

        int ty=goy+dy[d];
        int tx=gox+dx[d];

        //이동-> 왼쪽이나 오른족으로 가지 못하면 ???
        if(tx>=100 || tx<0 || ty>=100 || ty<0 || leader[ty][tx]==0){
            ty-=dy[d];
            tx-=dx[d];
            d=2 ;// 방향은 위로 간다.
            ty=goy+dy[d];
            tx=gox+dx[d];
        }

        return func(tx,ty,d);
    }

    public static void main(String[] args) {
        Scanner scann=new Scanner(System.in);
        for (int iT = 0; iT <10; iT++) {
            int N = scann.nextInt();
            int goy = 0, gox = 0;
            for(int i = 0 ; i < 100; i++) {
                for(int j = 0 ; j < 100; j++) {
                    leader[i][j] = scann.nextInt();
                    if(leader[i][j] == 2) {
                        goy = i;  //2가 있는 행 => 99
                        gox = j;  // 2가 있는 열
                    }
                }
            }

            int ans=func(gox,goy,2);
            System.out.println("#"+N+" "+ans);
        }
    }
}
