package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Boj1967 {
    static BufferedWriter bw;
    static int ans;
    static ArrayList<node>[] tree;

    static class node{
        int v;
        int w;

        public node(int v, int w) {
            this.v = v;
            this.w = w;
        }
    }

    static int dfs(int cur){
        if(tree[cur].size()==0)return 0;
        int m1=0,m2=0;

        for(node next:tree[cur]) {
            int k=next.w + dfs(next.v);
            if(k>m1){
                m2=m1;
                m1=k;
            }else if(k>m2){
                m2=k;
            }
        }

        if(m1+m2>ans)ans=m1+m2;
        return m1;

    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());

        tree=new ArrayList[n+1];

        for (int i = 0; i < n+1; i++) {
            tree[i]=new ArrayList<>();
        }

        for (int tc = 1; tc <= n-1; tc++) {
            st = new StringTokenizer(br.readLine());
            int u=Integer.parseInt(st.nextToken());
            tree[u].add(new node(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())));

        }

        int k=dfs(1);
        if(k>ans)ans=k;
        bw.write(ans+"");


        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }
}
