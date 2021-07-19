package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj1260 {
    static BufferedReader br;
    static BufferedWriter bw;
    static boolean[][] graph;
    static boolean[] visit;
    static int N,M,V;

    static void dfs(int cur)throws Exception{
        visit[cur]=true;
        bw.write(cur+" ");
        for (int i = 1; i <= N; i++) {
            if(graph[cur][i]&&!visit[i])
                dfs(i);
        }
    }

    static void bfs(int k)throws Exception{
        Queue<Integer> q=new LinkedList<>();

        visit[k]=true;
        q.offer(k);

        while(!q.isEmpty()){
            int cur=q.poll();
            bw.write(cur+" ");

            for (int i = 1; i <= N; i++) {
                if(graph[cur][i]&&!visit[i]){
                    visit[i]=true;
                    q.offer(i);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        V=Integer.parseInt(st.nextToken());
        graph=new boolean[N+1][N+1];
        visit=new boolean[N+1];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u=Integer.parseInt(st.nextToken());
            int v=Integer.parseInt(st.nextToken());
            graph[u][v]=graph[v][u]=true;
        }
        dfs(V);bw.write("\n");
        visit=new boolean[N+1];
        bfs(V);

        br.close();
        bw.flush();
        bw.close();

    }
}
