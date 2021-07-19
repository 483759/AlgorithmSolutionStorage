package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Swea1860 {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            int[] arr=new int[n];
            for (int i = 0; i < n; i++) {
                arr[i]=Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);

            boolean b=true;
            int t=0,boong=0,idx=0;
            while(idx!=n){
                if(t>0&&t%m==0)boong+=k;

                while(idx<n&&(arr[idx]==t)){
                    boong--;
                    idx++;
                }
                if(boong<0){
                    b=false;
                    break;
                }

                t++;
            }
            bw.write("#" + tc + " ");
            if (b) {
                bw.write("Possible\n");
            } else {
                bw.write("ImPossible\n");
            }
        }
        br.close();
        bw.flush();
        bw.close();

    }
}
