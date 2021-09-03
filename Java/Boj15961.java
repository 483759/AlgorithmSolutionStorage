package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Boj15961 {
    static BufferedWriter bw;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int d=Integer.parseInt(st.nextToken());
        int k=Integer.parseInt(st.nextToken());
        int c=Integer.parseInt(st.nextToken());

        int[] sushi=new int[n];
        Map<Integer,Integer> m=new HashMap<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            sushi[i]=Integer.parseInt(st.nextToken());
            if(!m.containsKey(sushi[i]))
                m.put(sushi[i],0);
        }
        if(!m.containsKey(c))
            m.put(c,0);

        int left=0,right=0,cnt=0,kind=0,answer=0;
        while(left!=n-1){
            if(cnt>=k){
                m.put(sushi[left],m.get(sushi[left])-1);
                if(m.get(sushi[left])==0)
                    kind--;
                left=(left+1)%n;
                cnt--;
            }else{
                if(m.get(sushi[right])==0)
                    kind++;
                m.put(sushi[right],m.get(sushi[right])+1);
                right=(right+1)%n;
                cnt++;
            }
            if(kind>=answer){
                answer=kind;
                if(m.get(c)==0)answer++;
            }
        }
        bw.write(answer+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
