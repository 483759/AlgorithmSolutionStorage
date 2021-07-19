package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj12873 {

    static int N, i, ans;
    static Queue<Integer> q;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        q = new LinkedList<>();

        for(int n=1; n<=N; n++) {
            q.offer(n);
        }

        souvenir();

        System.out.println(q.poll());
    }

    public static void souvenir() {
        i = 1;
        int size = N;

        q.poll();
        i += 1;
        size -= 1;

        long num = i * i * i % size; // 0~N-1 사이
        long cnt = 0;

        while (size > 1) {
            if (num == 0) {
                q.offer(q.poll());
                q.poll();
                continue;
            }
            if (cnt == num) {
                q.poll();

                cnt = 0;
                i += 1;
                size -= 1;
                num = i * i * i % size + 1;
                continue;
            }
            cnt += 1;
            q.offer(q.poll());
        }
    }

//    public static void main(String[] args) throws Exception{
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//
//        StringTokenizer st = new StringTokenizer(br.readLine());
//        int n=Integer.parseInt(st.nextToken());
//
//        Queue<Integer> q=new LinkedList<>();
//        for (int i = 0; i < n; i++) {
//            q.offer(i+1);
//        }
//
//        for (int i = 1; q.size()!=1; i++) {
//            int t=i;
//            t=(t*t*t)%q.size();
//
//            if(t==0)t=q.size();
//            for (int j = 0; j < t-1; j++) {
//                q.offer(q.poll());
//            }
//            q.poll();
//        }
//        System.out.println(q.poll());
//        //bw.write(q.poll());
//
//
//        br.close();
//        bw.flush();
//        bw.close();
//
//    }
}
