package list;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj17143 {
    static BufferedWriter bw;
    static int r,c;
    static int[] dr={0,-1,1,0,0},dc={0,0,0,1,-1};

    static class Point{
        int r,c;

        public Point(int r, int c) {
            this.r = r;
            this.c = c;
        }

        public boolean safe(){
            return this.c >= 0 && this.c < c && this.r >= 0 && this.r < r;
        }
    }

    static class Shark{
        Point p;
        int s,d,z,b;

        public Shark(Point p, int s, int d, int z, int b) {
            this.p = p;
            this.s = s;
            this.d = d;
            this.z = z;
            this.b = b;
        }
    }

    static Shark nextPoint(Shark s){
        int sp;
        if (s.d < 3) {
            int cur = s.p.r;
            sp = s.s % ((r - 1) * 2);

            cur += sp*dr[s.d];
            while (cur<0||cur>=r) {
                if (cur < 0) { s.d = 2; cur = cur * -1; }
                else if (cur >= r) { s.d = 1; cur = r - (cur - r) - 2; }
            }
            s.p.r = cur;
        }
        else {
            int cur = s.p.c;
            sp = s.s % ((c - 1) * 2);

            cur += sp*dc[s.d];
            while (cur < 0 || cur >= c) {
                if (cur < 0) { s.d = 3; cur = cur * -1; }
                else if (cur >= c) { s.d = 4; cur = c - (cur - c) - 2; }
            }
            s.p.c = cur;
        }
        return s;
    }



    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        r=Integer.parseInt(st.nextToken());
        c=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int[][] map=new int[r][c], temp=new int[r][c];
        ArrayList<Shark> li=new ArrayList<>();


        li.add(new Shark(new Point(0,0),0,0,0,0));
        for (int i = 1; i <= m; i++) {
            int x,y,s,d,z;
            st = new StringTokenizer(br.readLine());
            y=Integer.parseInt(st.nextToken());
            x=Integer.parseInt(st.nextToken());
            s=Integer.parseInt(st.nextToken());
            d=Integer.parseInt(st.nextToken());
            z=Integer.parseInt(st.nextToken());
            y--;x--;
            Shark S=new Shark(new Point(y,x),s,d,z,1);
            map[y][x]=i;
            li.add(S);

        }

        int ans=0;
        for (int j = 0; j < c; j++) {
            print(map);
            int cur=0;
            while ((cur < r) && map[cur][j]==0)cur++;
            if (cur < r) {
                int num = map[cur][j];
                ans+=li.get(num).z;
                Shark t = li.get(num);t.b=0;
                li.set(num,t);
                //li.get(num).b = 0;
                map[cur][j] = 0;
            }
            for (int i = 1; i < li.size(); i++) {
                if (li.get(i).b==0)continue;
                Shark next = nextPoint(li.get(i));
                int num = temp[next.p.r][next.p.c];
                if (num==0) {
                    li.set(i,next);
                    temp[li.get(i).p.r][li.get(i).p.c] = i;
                }
                else if (num == i)
                    li.set(i,next);
                else {
                    if (li.get(i).z >= li.get(num).z) {
                        li.set(i,next);
                        Shark t = li.get(num);t.b=0;
                        li.set(num,t);
                        temp[li.get(i).p.r][li.get(i).p.c] = i;
                    }
                    else{
                        Shark t = li.get(i);t.b=0;
                        li.set(i,t);
                    }
                        //li.get(i).b = 0;
                }
            }
            for (int i = 0; i < map.length; i++) {
                System.arraycopy(temp[i],0,map[i],0,temp[i].length);
            }
            for (int i = 0; i < temp.length; i++) {
                Arrays.fill(temp[i],0);
            }
        }
        print(map);

        bw.write(ans+"");

        br.close();
        bw.flush();
        bw.close();

    }

    private static void print(int[][] map) throws IOException {
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                bw.write(map[i][j]+" ");
            }
            bw.write('\n');
        }
        bw.write('\n');
    }
}
