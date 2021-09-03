package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj16926 {
    static int[][] arr;
    static BufferedReader br;
    static BufferedWriter bw;

    static void rotate(int r,int c,int w,int h) throws IOException {
        if(w<=1||h<=1)return;
        
        Queue<Integer> q=new LinkedList<>();
        q.offer(0);

        for (int i = 0; i < h; i++) {   //왼쪽 열
            q.offer(arr[r+i][c]);
            arr[r+i][c]=q.poll();
        }

        for (int i = 1; i < w; i++) {   //아래쪽 행
            q.offer(arr[r+h-1][c+i]);
            arr[r+h-1][c+i]=q.poll();
        }

        for (int i = h-2; i >=0; i--) { //오른쪽 열
            q.offer(arr[r+i][c+w-1]);
            arr[r+i][c+w-1]=q.poll();
        }

        for (int i = w-2; i >=0; i--) { //위쪽 행
            q.offer(arr[r][c+i]);
            arr[r][c+i]=q.poll();
        }

//        print(arr);
//        bw.write("\n");
        rotate(r+1,c+1,w-2,h-2);
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int r=Integer.parseInt(st.nextToken());
        arr=new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        
        while(r--!=0) {
            rotate(0, 0, m, n);
            //print(arr);
        }

        print(arr);
        br.close();
        bw.flush();
        bw.close();

    }

    private static void print(int[][] arr) throws IOException {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                bw.write(arr[i][j]+" ");
            }
            bw.write("\n");
        }
    }
}
