package Java;

import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj1074{
    static int n,r,c,idx;
    static BufferedWriter bw;

    class C implements Comparable<Integer>{
        int k;

        @Override
        public int compareTo(Integer o) {
            return 0;
        }
    }

    static boolean include(int x,int y,int k){
        return r>=x&&c>=y&&r<x+k&&c<y+k;
    }

    public static void divideAndConquer(int i,int j,int k) throws IOException {
        if(idx==-1)return;
        if(k==1){
            if(i==r&&j==c){
                bw.write(idx+"");
                idx=-1;
            }
            idx++;
            return;
        }

        int t=(k/2)*(k/2);

        if(include(i,j,k/2))
            divideAndConquer(i,j,k/2);
        else idx+=t;
        if(include(i,j+k/2,k/2))
            divideAndConquer(i,j+k/2,k/2);
        else idx+=t;
        if(include(i+k/2,j,k/2))
            divideAndConquer(i+k/2,j,k/2);
        else idx+=t;
        if(include(i+k/2,j+k/2,k/2))
            divideAndConquer(i+k/2,j+k/2,k/2);
        else idx+=t;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        n=(1<<n);
        r=Integer.parseInt(st.nextToken());
        c=Integer.parseInt(st.nextToken());

        divideAndConquer(0,0,n);

        br.close();
        bw.flush();
        bw.close();

    }
}
