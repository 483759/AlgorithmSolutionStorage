package list;

import java.io.FileInputStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Swea1225 {

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        Scanner sc=new Scanner(System.in);
        StringBuilder sb=new StringBuilder();


        for (int t = 0; t < 10; t++) {

            int tc=sc.nextInt();
            Queue<Integer> q=new LinkedList<>();


            for (int i = 0; i < 8; i++) {
                int k=sc.nextInt();
                q.offer(k);
            }

            int k=1;
            while(q.peek()-k>0){
                q.offer(q.poll()-k);
                k=(k%5)+1;
            }
            q.poll();
            q.offer(0);

            sb.append("#"+tc+" ");
            while(!q.isEmpty()){
                sb.append(q.poll()+" ");
            }
            sb.append("\n");

            System.out.println(sb);
        }
    }
}
