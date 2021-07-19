package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Boj2531 {
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
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            sushi[i]=Integer.parseInt(st.nextToken());
        }

        Map<Integer,Integer> m=new HashMap<Integer, Integer>();
        int left=0,right=0,ans;
        while(left!=n-1){
            int size=m.size();
            if(size<=k||m.containsKey(c)){
                right=(right+1)%n;
                if(m.containsKey(sushi[right])){
                    m.put(sushi[right], m.get(sushi[right]).intValue()+1);
                }else{
                    m.put(sushi[right], 1);
                }
            }
            if(m.size()>k){
                if(m.get(sushi[left]).intValue()==1)
                    m.remove(sushi[left]);
                else m.put(sushi[left], m.get(sushi[left]).intValue()-1);
                left=(left+1)%n;
            }
        }

        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
