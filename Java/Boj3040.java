package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj3040 {
    static int[] arr=new int[9];
    static BufferedWriter bw;

    static void func(int dep,int k,int sum,int[] check) throws IOException {
        if(dep==2){
            if(sum==100){
                for (int i = 0; i < 9; i++) {
                    if(check[0]==i||check[1]==i)continue;
                    bw.write(arr[i]+"\n");
                }
            }
            return;
        }

        for (int i = k; i < 9; i++) {
            check[dep]=i;
            func(dep+1,i+1,sum-arr[i],check);
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;
        int sum=0;

        for (int tc = 0; tc < 9; tc++) {
            st = new StringTokenizer(br.readLine());
            arr[tc]=Integer.parseInt(st.nextToken());
            sum+=arr[tc];
        }

        func(0,0,sum,new int[2]);

        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
