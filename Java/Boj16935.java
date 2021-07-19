package list;

import java.util.Arrays;
import java.util.Scanner;

public class Boj16935 {
    static int n,m;

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        StringBuilder sb=new StringBuilder();

        n=Integer.parseInt(sc.next());
        m=Integer.parseInt(sc.next());
        int r=Integer.parseInt(sc.next());

        int[] dx={1,0,-1,0},dy={0,1,0,-1};
        int[][] arr=new int[105][105];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j]=Integer.parseInt(sc.next());
            }
        }

        for (int k = 0; k < r; k++) {
            int[][] temp=new int[105][105];
            int op=Integer.parseInt(sc.next()),t;
            switch(op){
                case 1:
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            temp[i][j]=arr[n-1-i][j];
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            temp[i][j]=arr[i][m-1-j];
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            temp[j][n-1-i]=arr[i][j];
                        }
                    }
                    t=n;
                    n=m;
                    m=t;
                    break;
                case 4:
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            temp[m-1-j][i]=arr[i][j];
                        }
                    }
                    t=n;
                    n=m;
                    m=t;
                    break;
                case 5:
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            int d;
                            if(i<n/2) {
                                if (j < m / 2)
                                    d = 0;
                                else
                                    d = 1;
                            }
                            else{
                                if(j<m/2)d=3;
                                else d=2;
                            }

                            temp[i+dy[d]*(n/2)][j+dx[d]*(m/2)]=arr[i][j];
                        }
                    }
                    break;
                case 6:
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            int d;
                            if(i<n/2) {
                                if (j < m / 2)
                                    d = 1;
                                else
                                    d = 2;
                            }
                            else{
                                if(j<m/2)d=0;
                                else d=3;
                            }

                            temp[i+dy[d]*(n/2)][j+dx[d]*(m/2)]=arr[i][j];
                        }
                    }
                    break;

            }
            arr=temp;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sb.append(arr[i][j]+" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }
}
