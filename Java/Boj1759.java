package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Boj1759 {
    static BufferedWriter bw;
    static boolean[] apb=new boolean[26];
    static boolean[] a=new boolean[26];
    static char[] str=new char[26];
    static int[] vow={ 1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0 };
    static int L,C;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        L=Integer.parseInt(st.nextToken());
        C=Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < C; i++) {
            char k=st.nextToken().charAt(0);
            apb[k-'a']=true;
        }

        int j=0;
        for (int i = 0; i < 26; i++) {
            if(apb[i])str[j++]=(char)(i+'a');
        }
        str[j]='\0';

        func(0,0,0,0);

        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }

    private static void func(int d, int c, int v, int s) throws IOException {
        if (d == L) {
            if (c < 2 || v < 1)return;
            for(int i=0;i<26;i++)if(a[i])bw.write(i+'a');
            bw.write("\n");
            return;
        }
        for (int i = s; i < C; i++) {
            a[str[i]-'a'] = true;
            if (vow[str[i] - 'a']==1)func(d + 1, c, v + 1, i + 1);
            else func(d + 1, c + 1, v, i + 1);
            a[str[i] - 'a'] = false;
        }
    }
}
