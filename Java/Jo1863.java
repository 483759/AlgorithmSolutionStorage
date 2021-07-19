package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Jo1863 {
    static BufferedWriter bw;

    static class disjointSet{
        int[] parent,rank;

        public disjointSet(int n) {
            parent=new int[n+1];
            rank=new int[n+1];
            for (int i = 1; i <= n; i++) {
                parent[i]=i;
            }
        }

        int find(int x){
            if(x!=parent[x])
                parent[x]=find(parent[x]);
            return parent[x];
        }

        void union(int x,int y){
            x=find(x);
            y=find(y);
            int temp;

            if(x==y)return;
            if(rank[x]>rank[y]){
                temp=x;
                x=y;
                y=temp;
            }
            parent[x]=y;
            if(rank[x]==rank[y])
                rank[y]++;

        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());

        disjointSet ds=new disjointSet(n);
        for (int tc = 1; tc <= m; tc++) {
            st = new StringTokenizer(br.readLine());
            int u=Integer.parseInt(st.nextToken());
            int v=Integer.parseInt(st.nextToken());
            ds.union(u,v);
        }

        Set<Integer> s=new HashSet<>();
        for (int i = 1; i <= n; i++) {
            s.add(ds.find(i));
        }

        bw.write(s.size()+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
