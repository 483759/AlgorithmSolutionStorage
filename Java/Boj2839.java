package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj2839 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int ans=0;

        while(true){
            if(n<3||n%5==0)break;
            n=n-3;
            ans++;
        }
        if(n%5!=0){
            bw.write(-1+"");
        }else{
            ans+=n/5;
            bw.write(ans+"");
        }


        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
