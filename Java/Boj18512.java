package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj18512 {
    static BufferedWriter bw;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int x=Integer.parseInt(st.nextToken());
        int y=Integer.parseInt(st.nextToken());
        int a=Integer.parseInt(st.nextToken());
        int b=Integer.parseInt(st.nextToken());

        int[] arr=new int[205];
        for (int i = 0; i < 205; i++) {
            arr[i]=a+x*i;
        }

        int i=0;
        for (; i < 205; i++) {
            if(arr[i]>=b&&(arr[i]-b)%y==0){
                bw.write(arr[i]+"");
                break;
            }

        }


        if(i==205) bw.write("-1");

        br.close();
        bw.flush();
        bw.close();

    }
}
