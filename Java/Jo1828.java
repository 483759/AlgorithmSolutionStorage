package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Jo1828 {
    static class chem implements Comparable<chem>{
        int min;
        int max;

        chem(int min,int max){
            this.min=min;
            this.max=max;
        }

        @Override
        public int compareTo(chem o) {
            if(this.min==o.min)return Integer.compare(this.max,o.max);
            return Integer.compare(this.min,o.min);
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());

        PriorityQueue<chem> pq=new PriorityQueue<>();
        chem[] arr=new chem[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            arr[i]=new chem(a,b);
        }
        Arrays.sort(arr);

        int answer=1;
        int min=arr[0].min,max=arr[0].max;
        for (int i = 1; i < n; i++) {
            if(arr[i].min>max){
                answer++;
                min=arr[i].min;
                max=arr[i].max;
            }
            else{
                min=arr[i].min;
                max=Math.min(max,arr[i].max);
            }
        }

        bw.write(answer+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
