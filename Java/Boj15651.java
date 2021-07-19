package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj15651 {
    static int n,m;
    static int[] arr;
    static BufferedReader br;
    static BufferedWriter bw;


    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine()); // 01010001
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());

        arr=new int[n+1];
        st=new StringTokenizer((br.readLine()));
        for (int i = 0; i < n; i++) {
            arr[i]=Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        func(new int[m],0, 1);

        br.close();
        bw.flush();
        bw.close();;
    }

    static void func(int[] sel, int dep,int idx) throws IOException {
        if(dep==sel.length){
            for (int i = 0; i < dep; i++) {
                bw.write(sel[i]+" ");
            }
            bw.write("\n");
            return;
        }

        for (int i = idx; i <= n; i++) {
            sel[dep]=arr[i];
            func(sel,dep+1,i);
        }
    }
}
