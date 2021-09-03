package Java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Swea5656 {
    static BufferedWriter bw;
    static int n,w,h,ans;
    static int[] dx={1,0,-1,0},dy={0,1,0,-1};

    static class Point{
        int x,y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        boolean safe(){return this.x>=0&&this.x<w&&this.y>=0&&this.y<h;}
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T=Integer.parseInt(st.nextToken());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            n=Integer.parseInt(st.nextToken());
            w=Integer.parseInt(st.nextToken());
            h=Integer.parseInt(st.nextToken());
            ans=Integer.MAX_VALUE;

            int[][] map=new int[h][w];

            int b=0;    //현재 남아 있는 벽돌 개수
            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++) {
                    map[i][j]=Integer.parseInt(st.nextToken());
                    if(map[i][j]!=0)b++;
                }
            }

            dfs(map, 0, b);
            bw.write("#"+tc+" "+ans+"\n");
        }

        bw.write("");

        br.close();
        bw.flush();
        bw.close();

    }

    private static void print(int[][] map) throws IOException {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bw.write(map[i][j]+" ");
            }
            bw.write("\n");
        }
        bw.write("\n");
    }

    private static void dfs(int[][] map, int dep, int b) {
        if(dep==n||b==0){   //n개의 벽돌을 전부 떨어뜨리거나 더이상 깰 벽돌이 없을 때
            if(b<ans){  //최소값 갱신
                ans=b;
            }
            return;
        }

        int[][] temp=new int[h][w];     //맵 정보를 백업하기 위한 임시 배열
        for (int i = 0; i < h; i++) {
            System.arraycopy(map[i],0,temp[i],0,map[i].length);
        }

        for (int i = 0; i < w; i++) {
            Point p=new Point(i,0);
            while(p.safe()&&map[p.y][p.x]==0)p.y++;     //제일 위에 있는 벽돌을 만날 때 까지 내려감

            if(!p.safe())continue;      //만약 맵을 넘었다면? -> 해당 열에는 벽돌이 없음
                                        //굳이 깰 필요가 없으니까 pass

            int a = popBlock(map, p);   //현재 열의 top을 깨고 깨진 벽돌의 수 반환
            gravity(map);               //중력으로 모든 벽돌 내림
            dfs(map,dep+1,b-a);     //다음 경우


            for (int j = 0; j < h; j++) {       //백업해놓은 배열 복원
                System.arraycopy(temp[j],0,map[j],0,temp[j].length);
            }
        }
    }

    private static void gravity(int[][] map) {
        Queue<Integer> q=new LinkedList<>();        //중력 작용하기 위해 블럭을 담을 큐
        for (int j = 0; j < w; j++) {       //모든 열에 대해
            for (int i = h-1; i >= 0; i--) {    //아래에서부터 담는다
                if(map[i][j]!=0){       //블럭이 있는 곳이라면 큐에 담고 해당 칸을 비워줌
                    q.offer(map[i][j]);
                    map[i][j]=0;
                }
            }

            for (int i = h-1; i >= 0; i--) {        //다시 아래에서부터 쌓기
                if(q.isEmpty())break;
                map[i][j]=q.poll();
            }
        }
    }

    private static int popBlock(int[][] map, Point p) {
        int k=map[p.y][p.x],b=1;    //k: 현재 블록에 써진 숫자 저장, b: 현재 블록에서 연쇄해서 깨지는 벽돌의 개수
        map[p.y][p.x]=0;            //벽돌 깨짐
        for (int i = 0; i < 4; i++) {       //4 방향에 대해 검사
            for (int j = 1; j < k; j++) {       //블록에 써진 숫자의 범위만큼 다른 벽돌도 깨뜨림
                Point next=new Point(p.x+dx[i]*j,p.y+dy[i]*j);  //다음 좌표
                if(!next.safe())break;      //범위를 넘어가면 break
                if(map[next.y][next.x]==0)continue;     //비어있는 곳은 재귀 호출하면 안됨
                b+=popBlock(map, next);         //재귀 호출 하면서 연쇄 작용으로 깨지는 벽돌 수를 더함
            }
        }
        return b;       //깨진 벽돌 수 반환
    }
}
