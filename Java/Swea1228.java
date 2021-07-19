package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Swea1228 {

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int tc = 1; tc <= 10; tc++) {
            LinkedList<Integer> li= new LinkedList<>();

            StringTokenizer st = new StringTokenizer(br.readLine());
            int n=Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                li.offer(Integer.parseInt(st.nextToken()));
            }

            st = new StringTokenizer(br.readLine());
            int op=Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            while(op--!=0){
                String insert=st.nextToken();
                int x=Integer.parseInt(st.nextToken());
                int y=Integer.parseInt(st.nextToken());

                for (int i = 0; i < y; i++) {
                    int s=Integer.parseInt(st.nextToken());
                    li.add(x+i,s);
                }
            }

            bw.write("#"+tc+" ");
            for (int i = 0; i < 10; i++) {
                bw.write(li.get(i)+" ");
            }
            bw.write("\n");

        }




        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
