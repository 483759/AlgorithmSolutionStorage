package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Swea1233 {
    static String[] tree;
    static int n;
    static boolean ans;

    static void inorder(int cur){
        try{
            int t=Integer.parseInt(tree[cur]);
            if(cur*2<=n)ans=false;  //하나라도 자식이 있으면 false
        }catch(NumberFormatException e){
            if(cur*2+1>n)ans=false; //하나라도 자식이 없으면 false;
            inorder(cur*2);
            inorder(cur*2+1);
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));



        for (int tc = 1; tc <= 10; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n=Integer.parseInt(st.nextToken()); ans=true;

            tree=new String[n+1];
            for (int i = 1; i <= n; i++) {
                st = new StringTokenizer(br.readLine());

                int a=Integer.parseInt(st.nextToken());
                tree[i]=st.nextToken();
                if(st.countTokens()==4) {
                    int c = Integer.parseInt(st.nextToken());
                    int d = Integer.parseInt(st.nextToken());
                }
            }
            inorder(1);
            bw.write("#"+tc+" ");
            bw.write(ans?"1\n":"0\n");
        }




        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
