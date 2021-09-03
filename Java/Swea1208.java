package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Swea1208 {

    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        for (int tc = 1; tc <= 10; tc++) {
            int ans=0;
            int[] box=new int[105];
            st=new StringTokenizer(in.readLine());
            int dump=Integer.parseInt(st.nextToken());

            st=new StringTokenizer(in.readLine());
            for (int i = 0; i < 100; i++) {
                box[i]=Integer.parseInt(st.nextToken());
            }

            int max=0,min=0;
            while(dump--!=0){
                max=0;min=0;
                for (int i = 0; i < 100; i++) {
                    if(box[i]>box[max])max=i;
                    if(box[i]<box[min])min=i;
                }

                if(box[max]-box[min]<=1)break;
                box[max]--;box[min]++;
            }
            max=0;min=0;
            for (int i = 0; i < 100; i++) {
                if(box[i]>box[max])max=i;
                if(box[i]<box[min])min=i;
            }
            ans=box[max]-box[min]+2;
            System.out.println("#"+tc+" "+ans);
            out.write("#"+tc+" "+ans+2+"\n");
        }
    }
}
