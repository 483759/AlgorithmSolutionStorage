package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Swea3499 {
    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());

            String[] s=new String[n];
            Queue<String> q1=new LinkedList<>();
            Queue<String> q2=new LinkedList<>();

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                s[i]=st.nextToken();
                if(n%2==1){
                    if(i<((n+1)/2))
                        q1.offer(s[i]);
                    else q2.offer(s[i]);
                }else{
                    if(i<n/2)
                        q1.offer(s[i]);
                    else q2.offer(s[i]);
                }

            }

            for (int i = 0; i < n; i++) {
                if(i%2==0){
                    bw.write(q1.poll()+" ");
                }else{
                    bw.write(q2.poll()+" ");
                }
            }

        }

        br.close();
        bw.flush();
        bw.close();

    }
}
