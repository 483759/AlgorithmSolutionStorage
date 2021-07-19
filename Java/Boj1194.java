package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Boj1194 {
    static BufferedWriter bw;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};
    static int n,m;

    static class msik{
        int x,y,key;

        public msik(int x, int y, int key) {
            this.x = x;
            this.y = y;
            this.key = key;
        }

        public boolean safe(){
            return x>=0&&x<m&&y>=0&&y<n;
        }
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        char[][] map=new char[n][m];
        boolean[][][] visit=new boolean[64][n][m];
        Queue<msik> q=new LinkedList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            map[i]=new char[m];
            map[i]=st.nextToken().toCharArray();
            for (int j = 0; j < m; j++) {
                if(map[i][j]=='0'){
                    q.offer(new msik(j,i,0));
                    visit[0][i][j]=true;
                }
            }
        }

        int time=0,ans=-1;
        L:while(!q.isEmpty()){
            int size=q.size();
            while(size--!=0){
                msik cur=q.poll();

                if(map[cur.y][cur.x]=='1'){
                    ans=time;
                    break L;
                }
                for (int i = 0; i < 4; i++) {
                    msik next=new msik(cur.x+dx[i],cur.y+dy[i],cur.key);
                    if(!next.safe()||visit[cur.key][next.y][next.x]||map[next.y][next.x]=='#')continue;

                    boolean b=false;

                    char k=map[next.y][next.x];

                    if(k>='A'&&k<='F'&&(next.key>>(k-'A')&1)!=1)
                        continue;
                    if(k>='a'&&k<='f')
                        next.key|=1<<(k-'a');

                    visit[next.key][next.y][next.x]=true;
                    q.offer(next);
                }
            }
            time++;
        }

        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }
}
